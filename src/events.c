/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 06:10:57 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/09/21 06:06:42 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static double	interpolate(double start, double end, double interpolation)
{
	return(start + ((end - start) * interpolation));
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
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	t_complex mouse;
	double	interpolation;
	double	zoom;

	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		mouse = init_complex(
			(double)x / (WIDTH / (fractal->max.x - fractal->min.x))
				+ fractal->min.x,
			(double)y / (HEIGHT / (fractal->max.y - fractal->min.y))
				* -1 + fractal->max.y);
		if (button == Button5)
			fractal->zoom *= 0.95;
		else
			fractal->zoom *= 1.05;
		interpolation = 1.0 / fractal->zoom;
		fractal->min.x = interpolate(mouse.x, fractal->min.x, interpolation);
		fractal->min.y = interpolate(mouse.y, fractal->min.y, interpolation);
		fractal->max.x = interpolate(mouse.x, fractal->max.x, interpolation);
		fractal->max.y = interpolate(mouse.y, fractal->max.y, interpolation);
		fractal_render(fractal);
	}
	return (0);
}

int julia_track(int x, int y, t_fractal *fractal)
{
	if(!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_k = init_complex(
			4 * ((double)x / WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		fractal_render(fractal);
	}
	return (0);
}
