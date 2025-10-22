/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 06:22:35 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/22 14:32:29 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
** map: Mapeia um valor de um intervalo para outro
** 
** Converte valores do domínio [0, old_max] para [new_min, new_max]
** Usado para converter coordenadas de pixel para plano complexo
** 
** Parâmetros:
**   - value: Valor a ser convertido
**   - new_min: Novo mínimo do intervalo
**   - new_max: Novo máximo do intervalo  
**   - old_max: Antigo máximo do intervalo (mínimo é 0)
** 
** Retorna:
**   - Valor convertido para novo intervalo
*/
double	map(double value,
			double new_min,
			double new_max,
			double old_max)
{
	return ((new_max - new_min)
		* (value - 0)
		/ (old_max - 0)
		+ new_min);
}

/*
** init_complex: Inicializa número complexo com coordenadas x,y
** 
** Parâmetros:
**   - x: Parte real
**   - y: Parte imaginária
** 
** Retorna:
**   - Estrutura t_complex inicializada
*/
t_complex	init_complex(double x, double y)
{
	t_complex	z;

	z.x = x;
	z.y = y;
	return (z);
}
