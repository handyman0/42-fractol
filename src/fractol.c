/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:55:02 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/09/29 02:01:16 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		fractal.name = "mandelbrot";
	else if (argc == 2 && !ft_strncmp(argv[1], "celtic", 7))
		fractal.name = "celtic";
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 6))
	{
		fractal.name = "julia";
		fractal.k = init_complex(ft_atodbl(argv[2]), ft_atodbl(argv[3]));
	}
	else
	{
		ft_putstr_fd("Please enter\n"
			"\t\"./fractol mandelbrot\" or\n"
			"\t\"./fractol julia <value_1> <value_2>\"\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
	return (0);
}
