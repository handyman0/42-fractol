/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:55:02 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/09/28 19:31:49 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
