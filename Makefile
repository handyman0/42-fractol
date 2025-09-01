# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 16:34:59 by lmelo-do          #+#    #+#              #
#    Updated: 2025/09/01 11:14:20 by lmelo-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC += $(addprefix src/, ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c )
OBJS = ${SRC:.c=.o}

INCLUDE = include

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAKEFLAGS += --no-print-directory

%.o:%.c ${INCLUDE}
	${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all


.PHONY: all clean fclean re
