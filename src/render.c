/* render.c — correções mínimas para thread + pixel put */
#include "../include/fractol.h"
#include <pthread.h>

/*
 * Escreve 4 bytes do color.channel no buffer da img.
 * Proteções: verifica limites via line_len e bits_per_pixel.
 */
static void my_pixel_put(int x, int y, t_img *img, t_color color)
{
    unsigned char *buf;
    size_t offset;
    int bytes_per_pixel;

    if (!img || !img->pixel_ptr)
        return;
    if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
        return;

    bytes_per_pixel = img->bits_per_pixel / 8;
    offset = (size_t)y * (size_t)img->line_len + (size_t)x * (size_t)bytes_per_pixel;
    buf = (unsigned char *)img->pixel_ptr;

    /* Proteção extra: (não obrigatório, mas seguro)
       se offset + bytes_per_pixel ultrapassar line_len*HEIGHT, abborta */
    /* aqui assumimos buffer alocado corretamente pela mlx_new_image */

    /* Escrita byte-a-byte (ordem dos canais depende do teu uso/endian) */
    buf[offset + 0] = color.channel[0];
    if (bytes_per_pixel > 1) buf[offset + 1] = color.channel[1];
    if (bytes_per_pixel > 2) buf[offset + 2] = color.channel[2];
    if (bytes_per_pixel > 3) buf[offset + 3] = color.channel[3];
}

/*
 * Função que cada thread vai executar.
 * Assinatura compatível com pthread: void *fn(void *arg)
 * Recebe um ponteiro para uma cópia de t_fractal (como você já fazia).
 */
static void *fractal_render_part(void *arg)
{
    t_fractal *fractol;
    int y;
    int x;
    t_color color;
    int max_x;

    fractol = (t_fractal *)arg;
    if (!fractol)
        return (NULL);

    y = fractol->start_line;
    max_x = WIDTH;
    while (y < fractol->finish_line)
    {
        fractol->c.im = fractol->max.im - (double)y * fractol->factor.im;
        x = 0;
        while (x < max_x)
        {
            fractol->c.re = fractol->min.re + (double)x * fractol->factor.re;
            color = get_color(fractol->formula(fractol), fractol);
            my_pixel_put(x, y, &fractol->img, color);
            x++;
        }
        y++;
    }
    return (NULL);
}

/*
 * Função principal que cria/junta threads e desenha.
 * Mantive a tua lógica de copiar struct pra cada thread.
 */
void fractal_render(t_fractal *fractal)
{
    pthread_t threads[THREADS];
    t_fractal fractols[THREADS];
    int i;

    if (!fractal)
        return;

    fractal->factor = init_complex(
        (fractal->max.re - fractal->min.re) / (WIDTH - 1),
        (fractal->max.im - fractal->min.im) / (HEIGHT - 1));

    for (i = 0; i < THREADS; ++i)
    {
        fractols[i] = *fractal;
        fractols[i].start_line = i * (HEIGHT / THREADS);
        fractols[i].finish_line = (i + 1) * (HEIGHT / THREADS);
        if (pthread_create(&threads[i], NULL, fractal_render_part, &fractols[i]) != 0)
            terminate(ERR_TREADS);
    }
    for (i = 0; i < THREADS; ++i)
    {
        if (pthread_join(threads[i], NULL) != 0)
            terminate(ERR_TREADS);
    }
    /* Depois que todas as threads terminaram, manda a imagem para a janela */
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
                            fractal->img.img_ptr, 0, 0);
}
