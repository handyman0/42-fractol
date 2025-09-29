/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:30:10 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/09/29 00:18:55 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	run_mandelbrot(t_fractal *fractal)
{
	int		iteration;
	double	zx;
	double	zy;
	double	xtemp;

	iteration = 0;
	zx = 0.0;
	zy = 0.0;
	while (iteration < fractal->iterations_definition
		&& (zx * zx + zy * zy) <= 4.0)
	{
		xtemp = zx * zx - zy * zy + fractal->c.x;
		zy = 2.0 * zx * zy + fractal->c.y;
		zx = xtemp;
		iteration++;
	}
	return (iteration);
}
