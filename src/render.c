/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 06:10:50 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/22 14:15:53 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
** my_pixel_put: Escreve um pixel na imagem MLX
** 
** Calcula offset correto baseado em line_len e bpp (bits per pixel)
** 
** Parâmetros:
**   - x, y: Coordenadas do pixel
**   - img: Estrutura da imagem (apenas leitura)
**   - color: Cor em formato inteiro (0xRRGGBB)
*/
void	my_pixel_put(int x, int y, const t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

/*
** fractal_render: Renderiza o fractal completo
** 
** Itera por todos os pixels da tela, calcula valor fractal para cada um
** e atualiza a imagem. Finalmente exibe a imagem na janela.
** 
** Parâmetros:
**   - fractal: Estrutura fractal com dados e conexão MLX
*/
void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window,
		fractal->img.img_ptr,
		0,
		0);
}
