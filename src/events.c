/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 06:10:57 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/09/29 01:53:13 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* converte coordenadas de pixel (x,y) -> ponto complexo (re,im)
   mesma fórmula usada em render.c */
static void	pixel_to_complex(t_fractal *f, int x, int y, t_complex *out)
{
	out->x = (map(x, -2.0, 2.0, WIDTH) * f->zoom) + f->shift_x;
	out->y = (map(y, 2.0, -2.0, HEIGHT) * f->zoom) + f->shift_y;
}

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == KEY_ESC)
		close_handler(fractal);
	else if (keysym == KEY_LEFT)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == KEY_RIGHT)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == KEY_UP)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == KEY_DOWN)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == KEY_PLUS)
		fractal->iterations_definition += 10;
	else if (keysym == KEY_MINUS)
		fractal->iterations_definition -= 10;
	if (fractal->iterations_definition < 1)
		fractal->iterations_definition = 1;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	t_complex	cursor;
	double		factor;
	double		new_zoom;

	(void)y;
	if (button != Button4 && button != Button5)
		return (0);
	pixel_to_complex(fractal, x, y, &cursor);
	if (button == Button5)
		factor = 1.05;
	else
		factor = 0.95;
	new_zoom = fractal->zoom * factor;
	fractal->zoom = new_zoom;
	fractal->shift_x = cursor.x
		- (map(x, -2.0, 2.0, WIDTH) * fractal->zoom);
	fractal->shift_y = cursor.y
		- (map(y, 2.0, -2.0, HEIGHT) * fractal->zoom);
	if (fractal->zoom <= 1e-18)
		fractal->zoom = 1e-18;
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 6))
	{
		fractal->k = init_complex(
				4.0 * ((double)x / (double)WIDTH - 0.5),
				4.0 * ((double)(HEIGHT - y) / (double)HEIGHT - 0.5));
		fractal_render(fractal);
	}
	return (0);
}
