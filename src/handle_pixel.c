/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 06:10:50 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/22 14:03:15 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
** handle_pixel: Processa um pixel individual do fractal
** 
** Converte coordenadas de tela para plano complexo, calcula iterações
** e determina a cor baseada no conjunto fractal
** 
** Parâmetros:
**   - x, y: Coordenadas do pixel na tela
**   - fractal: Estrutura fractal para cálculo
*/
void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	int			iter;
	int			color;

	z.x = (map(x, -2.0, 2.0, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, 2.0, -2.0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	fractal->c = z;
	if (!ft_strncmp(fractal->name, "mandelbrot", 11))
		iter = run_mandelbrot(fractal);
	else if (!ft_strncmp(fractal->name, "celtic", 7))
		iter = run_celtic(fractal);
	else if (!ft_strncmp(fractal->name, "julia", 6))
		iter = run_julia(fractal);
	else
		iter = run_mandelbrot(fractal);
	if (iter < fractal->iterations_definition)
		color = (int)map(iter, WHITE, BLACK, fractal->iterations_definition);
	else
		color = BLACK;
	my_pixel_put(x, y, &fractal->img, color);
}
