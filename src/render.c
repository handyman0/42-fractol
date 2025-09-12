/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 06:10:50 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/09/12 06:35:32 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;

	z.x = 0.0;
	z.y = 0.0;

	c.y = map(x, -2, +2, 0, WIDTH);
	c.y = map(x, -2, +2, 0, HEIGHT);
}

void	fractal_render(t_fractal *fractal)
{
	int x;
	int y;

	y = -1;
	while(y < HEIGHT)
	{
		x = -1;
		while(x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			++x;
		}
		++y;
	}
}
