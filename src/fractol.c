/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:55:02 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/09/23 16:20:00 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* 
1 - arrumar header
	1.1 - arrumar includes
	1.2 - arrumar prototypes
2 - arrumar make
	2.1 - arrumar wildcards
3 - rever documentação
	3.1 - principalmente inclusões de funções tipo(fabs e pow)
4 - possibilidade de apagar math_utils.c
5 - estudar melhor pthreads (ficar facil para o philosophers)
*/
#include "../include/fractol.h"

static void	setup_and_run(char *name, int (*formula)(t_fractal *), char **argv)
{
	t_fractal	fractal;

	set_defaults(&fractal);
	fractal.formula = formula;
	fractal.name = name;
	if (!ft_strncmp(name, "julia", 5) && argv)
		fractal.k = init_complex(ft_atodbl(argv[2]), ft_atodbl(argv[3]));
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		setup_and_run("mandelbrot", run_mandelbrot, NULL);
	else if (argc == 2 && !ft_strncmp(argv[1], "celtic", 7))
		setup_and_run("celtic", run_celtic, NULL);
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 6))
		setup_and_run("julia", run_julia, argv);
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		ft_putstr_fd("Usage:\n  ./fractol mandelbrot\n", STDERR_FILENO);
		ft_putstr_fd("  ./fractol celtic\n", STDERR_FILENO);
		ft_putstr_fd("  ./fractol julia <re> <im>\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
