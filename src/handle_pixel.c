/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 06:10:50 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/09/29 00:24:11 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	pixel_to_complex(int x, int y, t_fractal *fractal, t_complex *out)
{
	out->x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	out->y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
}

static void	mandel_or_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 6))
	{
		c->x = fractal->k.x;
		c->y = fractal->k.y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static int	compute_iterations(t_complex z, t_complex c, t_fractal *fractal)
{
	double	zx;
	double	zy;
	double	zx2;
	double	zy2;
	int		i;

	zx = z.x;
	zy = z.y;
	zx2 = zx * zx;
	zy2 = zy * zy;
	i = 0;
	while (i < fractal->iterations_definition
		&& (zx2 + zy2) <= fractal->escape_value)
	{
		zy = 2.0 * zx * zy + c.y;
		zx = zx2 - zy2 + c.x;
		zx2 = zx * zx;
		zy2 = zy * zy;
		++i;
	}
	return (i);
}

static int	color_from_iterations(int iterations, t_fractal *fractal)
{
	if (iterations < fractal->iterations_definition)
		return ((int)map(iterations, BLACK, WHITE,
				fractal->iterations_definition));
	return (WHITE);
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			iter;
	int			color;

	pixel_to_complex(x, y, fractal, &z);
	mandel_or_julia(&z, &c, fractal);
	iter = compute_iterations(z, c, fractal);
	color = color_from_iterations(iter, fractal);
	my_pixel_put(x, y, &fractal->img, color);
}
