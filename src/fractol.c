/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:55:02 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/09/21 06:02:48 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	run_mandelbrot(void)
{
	t_fractal	fractal;

	fractal.name = "mandelbrot";
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
}

static void	run_celtic(void)
{
	t_fractal	fractal;

	fractal.name = "celtic";
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
}

static void	run_julia(char **argv)
{
	t_fractal	fractal;

	fractal.name = "julia";
	fractal.julia_x = ft_atodbl(argv[2]);
	fractal.julia_y = ft_atodbl(argv[3]);
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		run_mandelbrot();
	else if (argc == 2 && !ft_strncmp(argv[1], "celtic", 7))
		run_celtic();
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 6))
		run_julia(argv);
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		ft_putstr_fd("Usage:\n  ./fractol mandelbrot\n  ./fractol celtic\n  ./fractol julia <re> <im>\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
