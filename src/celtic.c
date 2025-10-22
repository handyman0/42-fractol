/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:28:50 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/22 14:00:06 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
/*
** run_celtic: Calcula iterações para o fractal Celtic
** 
** O fractal Celtic é uma variação do Mandelbrot que usa valor absoluto
** na parte real, criando padrões simétricos e angulares distintos.
** Fórmula: z = |z_real² - z_imag²| + 2*z_real*z_imag*i + c
** 
** Parâmetros:
**   - fractal: Estrutura com dados do fractal (apenas leitura)
** 
** Retorna:
**   - Número de iterações até divergência ou iterations_definition
*/
int	run_celtic(const t_fractal *fractal)
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
