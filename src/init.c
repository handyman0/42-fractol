/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 06:10:57 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/22 14:29:45 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
** malloc_error: Manipulador de erro para falhas de alocação de memória
** 
** Exibe mensagem de erro via perror e finaliza o programa com falha
** Usado quando mlx_init, mlx_new_window ou mlx_new_image falham
*/
static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

/*
** data_init: Inicializa parâmetros numéricos do fractal
** 
** Define valores padrão para:
**   - escape_value: Limite para determinar divergência (4 para |z|²)
**   - iterations_definition: Número máximo de iterações por pixel
**   - shift_x, shift_y: Deslocamento do centro da visualização
**   - zoom: Fator de zoom inicial (1.0 = zoom normal)
** 
** Parâmetros:
**   - fractal: Estrutura fractal a ser inicializada
*/
static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

/*
** events_init: Configura hooks de eventos do MLX
** 
** Associa funções de callback aos eventos da janela:
**   - KeyPress: Teclado (key_handler)
**   - ButtonPress: Mouse (mouse_handler)  
**   - DestroyNotify: Fechamento da janela (close_handler)
**   - MotionNotify: Movimento do mouse (julia_track para Julia dinâmico)
** 
** Parâmetros:
**   - fractal: Estrutura fractal contendo janela MLX
*/
static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window,
		KeyPress,
		KeyPressMask,
		key_handler,
		fractal);
	mlx_hook(fractal->mlx_window,
		ButtonPress,
		ButtonPressMask,
		mouse_handler,
		fractal);
	mlx_hook(fractal->mlx_window,
		DestroyNotify,
		StructureNotifyMask,
		close_handler,
		fractal);
	mlx_hook(fractal->mlx_window,
		MotionNotify,
		PointerMotionMask,
		julia_track,
		fractal);
}

/*
** fractal_init: Inicialização completa do sistema fractal
** 
** Sequência de inicialização:
**   1. Conexão MLX com servidor X11
**   2. Criação da janela
**   3. Criação do buffer de imagem
**   4. Configuração de eventos
**   5. Inicialização de parâmetros
** 
** Limpeza em caso de erro: Libera recursos alocados até o ponto da falha
** 
** Parâmetros:
**   - fractal: Estrutura fractal a ser inicializada
*/
void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}
