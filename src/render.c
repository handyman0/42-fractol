/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 06:10:50 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/09/20 23:28:48 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

static void mandel_or_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex z, c;
	int color = WHITE;
	double zx, zy, zx2, zy2;
	int i = 0;

	z.x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;

	mandel_or_julia(&z, &c, fractal);

	zx = z.x;
	zy = z.y;
	zx2 = zx * zx;
	zy2 = zy * zy;

	while (i < fractal->iterations_definition && (zx2 + zy2) <= fractal->escape_value)
	{
		zy = 2 * zx * zy + c.y;
		zx = zx2 - zy2 + c.x;
		zx2 = zx * zx;
		zy2 = zy * zy;
		++i;
	}
	if (i < fractal->iterations_definition)
		color = map(i, BLACK, WHITE, 0, fractal->iterations_definition);
	my_pixel_put(x, y, &fractal->img, color);
}

void	fractal_render(t_fractal *fractal)
{
	int x;
	int y;

	y = 0;
	while(y < HEIGHT)
	{
		x = 0;
		while(x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}
