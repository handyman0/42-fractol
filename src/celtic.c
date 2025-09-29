/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:28:50 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/09/29 03:34:58 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	run_celtic(t_fractal *fractal)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractal->c.x, fractal->c.y);
	while (z.x * z.x + z.y * z.y <= 4
		&& iteration < fractal->iterations_definition)
	{
		z = init_complex(
				fabs(z.x * z.x - z.y * z.y) + fractal->c.x,
				2.0 * z.x * z.y + fractal->c.y);
		iteration++;
	}
	return (iteration);
}
