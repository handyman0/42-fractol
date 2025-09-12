# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 16:34:59 by lmelo-do          #+#    #+#              #
#    Updated: 2025/09/12 04:46:50 by lmelo-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fractol

SRC_DIR = src
INC_DIR = include
LIBFT_DIR = libft
MLX_DIR = minilibx-linux

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRC:.c=.o)
CC  = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)/include -I$(MLX_DIR)
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx_Linux.a

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT} ${MLX}
	${CC} ${OBJS} -o ${NAME} ${LIBFT} ${MLX} -lX11 -lXext -lm

${LIBFT}:
	${MAKE} -C ${LIBFT_DIR}

${MLX}:
	@if [ ! -d "${MLX_DIR}" ]; then \
		echo ">> Desempacotando minilibx-linux..."; \
		tar -xzf minilibx-linux.tgz; \
	fi
	${MAKE} -C ${MLX_DIR}

valgrind: ${NAME}
	valgrind --leak-check=full --show-leak-kinds=all ./${NAME} mandelbrot

gdb: ${NAME}
	gdb ./${NAME}

clean:
	rm -f ${OBJS}
	${MAKE} -C ${LIBFT_DIR} clean
	@if [ -d "${MLX_DIR}" ]; then ${MAKE} -C ${MLX_DIR} clean; fi

fclean: clean
	rm -f ${NAME}
	${MAKE} -C ${LIBFT_DIR} fclean

re: fclean all

.PHONY: all clean fclean re valgrind gdb
