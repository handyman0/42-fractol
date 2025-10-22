/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:30:10 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/22 14:12:59 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
** run_mandelbrot: Calcula iterações para o conjunto de Mandelbrot
** 
** Fórmula clássica: z = z² + c
** Testa se sequência permanece limitada para cada ponto c no plano complexo
** 
** Parâmetros:
**   - fractal: Estrutura com dados do fractal
** 
** Retorna:
**   - Número de iterações até divergência ou iterations_definition
*/
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
