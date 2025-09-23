/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 06:10:57 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/09/21 16:30:00 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, close_handler, fractal);
	mlx_hook(fractal->mlx_window, MotionNotify, PointerMotionMask, julia_track, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		malloc_error();

	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);
	if (!fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}

	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}

	fractal->img.pixel_ptr = mlx_get_data_addr(
		fractal->img.img_ptr,
		&fractal->img.bits_per_pixel,
		&fractal->img.line_len,
		&fractal->img.endian);

	events_init(fractal);
}

t_complex	init_complex(double x, double y)
{
	t_complex	z;

	z.x = x;
	z.y = y;
	return (z);
}

void	set_defaults(t_fractal *fractal)
{
	fractal->iterations_definition = 42;
	fractal->min = init_complex(-2.0, -2.0);
	fractal->max = init_complex(2.0, 2.0);
	fractal->julia_k = init_complex(-0.4, 0.6);

	/* Ajuste para manter proporção de aspect ratio */
	fractal->max.y = fractal->min.y
		+ (fractal->max.x - fractal->min.x) * HEIGHT / WIDTH;

	/* Se quiser color_shift, adicione no header */
	/* fractal->color_shift = 0; */
}
