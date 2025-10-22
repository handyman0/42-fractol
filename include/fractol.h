/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 06:11:11 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/10/22 14:51:26 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 800
# define HEIGHT 800

# define BLACK               0x000000
# define WHITE               0xFFFFFF
# define RED                 0xFF0000
# define GREEN               0x00FF00
# define BLUE                0x0000FF

# define NEON_GREEN           0x39FF14
# define NEON_BLUE            0x1F51FF
# define LIME                 0xBFFF00
# define GOLD                 0xFFD700
# define PSYCHEDELIC_PURPLE   0x660066
# define HOT_PINK             0xFF69B4
# define CYAN                 0x00FFFF
# define ORANGE               0xFF5F1F
# define VIVID_YELLOW         0xF7FF00
# define NEON_ORANGE          0xFF6E00
# define ULTRA_PINK           0xFF007F
# define TURQUOISE            0x40E0D0
# define COSMIC_LIME          0xA7FF00
# define LASER_LEMON          0xFFFF66

# define KEY_ESC 0xff1b
# define KEY_PLUS 0xffab
# define KEY_MINUS 0xffad
# define KEY_LEFT 0xff51
# define KEY_RIGHT 0xff53
# define KEY_UP 0xff52
# define KEY_DOWN 0xff54

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_fractal
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_img		img;
	double		escape_value;
	int			iterations_definition;
	double		shift_x;
	double		shift_y;
	double		zoom;
	t_complex	c;
	t_complex	k;
}				t_fractal;

void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
double		map(double unscaled_num,
				double new_min,
				double new_max,
				double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			key_handler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);
t_complex	init_complex(double x, double y);
void		my_pixel_put(int x, int y, const t_img *img, int color);
void		handle_pixel(int x, int y, t_fractal *fractal);
int			run_mandelbrot(t_fractal *fractal);
int			run_celtic(const t_fractal *fractal);
int			run_julia(const t_fractal *fractal);

#endif
