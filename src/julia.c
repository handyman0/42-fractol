/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:30:03 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/22 14:12:33 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
** run_julia: Calcula iterações para o conjunto de Julia
** 
** Diferente do Mandelbrot, Julia usa uma constante fixa (k) e varia
** o ponto inicial (c). Fórmula: z = z² + k
** 
** Parâmetros:
**   - fractal: Estrutura com dados do fractal (apenas leitura)
** 
** Retorna:
**   - Número de iterações até divergência ou iterations_definition
*/
int	run_julia(const t_fractal *fractal)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractal->c.x, fractal->c.y);
	while (z.x * z.x + z.y * z.y <= 4
		&& iteration < fractal->iterations_definition)
	{
		z = init_complex(
				z.x * z.x - z.y * z.y + fractal->k.x,
				2.0 * z.x * z.y + fractal->k.y);
		iteration++;
	}
	return (iteration);
}
