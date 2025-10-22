# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/17 05:20:06 by lmelo-do          #+#    #+#              #
#    Updated: 2025/10/22 14:46:47 by lmelo-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = src
INC_DIR = include
LIBFT_DIR = libft
MLX_DIR = minilibx-linux

GREEN	= \033[0;32m
BLUE	= \033[0;34m
YELLOW	= \033[0;33m
RED		= \033[0;31m
CYAN	= \033[0;36m
MAGENTA	= \033[0;35m
RESET	= \033[0m
BOLD	= \033[1m

SRC = $(SRC_DIR)/celtic.c \
      $(SRC_DIR)/events.c \
      $(SRC_DIR)/julia.c \
      $(SRC_DIR)/mandelbrot.c \
      $(SRC_DIR)/fractol.c \
      $(SRC_DIR)/handle_pixel.c \
      $(SRC_DIR)/math_utils.c \
      $(SRC_DIR)/init.c \
      $(SRC_DIR)/render.c

OBJS = $(SRC:.c=.o)

CC  = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)/include -I$(MLX_DIR)

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx_Linux.a

all: ${NAME}

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "$(CYAN)$(BOLD)🔗 Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX) -lX11 -lXext -lm
	@echo "$(GREEN)$(BOLD)✨ $(NAME) compiled successfully!$(RESET)"

%.o: %.c
	@echo "$(BLUE)📦 Compiling $(notdir $<)...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "$(MAGENTA)📚 Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --silent

$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "$(YELLOW)📦 Unpacking minilibx-linux...$(RESET)"; \
	fi
	@echo "$(MAGENTA)🎨 Building minilibx...$(RESET)"
	@$(MAKE) -C $(MLX_DIR) --silent

gdb: $(NAME)
	@echo "$(YELLOW)🐛 Starting debugger...$(RESET)"
	@gdb ./$(NAME)

clean:
	@echo "$(YELLOW)🧹 Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) -C $(MLX_DIR) clean --silent; fi
	@echo "$(GREEN)✅ Clean completed!$(RESET)"

fclean: clean
	@echo "$(YELLOW)🗑️  Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent
	@echo "$(GREEN)✅ Full clean completed!$(RESET)"

re: fclean
	@echo "$(CYAN)$(BOLD)🔄 Rebuilding $(NAME)...$(RESET)"
	@$(MAKE) all --silent

help:
	@echo "$(BOLD)$(CYAN)🤖 Fractol Makefile Help$(RESET)"
	@echo ""
	@echo "$(GREEN)Available targets:$(RESET)"
	@echo "  $(YELLOW)all$(RESET)     - Build the fractol executable (default)"
	@echo "  $(YELLOW)clean$(RESET)   - Remove object files"
	@echo "  $(YELLOW)fclean$(RESET)  - Remove object files and executable"
	@echo "  $(YELLOW)re$(RESET)      - Rebuild everything from scratch"
	@echo "  $(YELLOW)gdb$(RESET)     - Build and start debugger"
	@echo "  $(YELLOW)help$(RESET)    - Show this help message"
	@echo ""
	@echo "$(GREEN)Usage:$(RESET)"
	@echo "  $(CYAN)make$(RESET)           - Build fractol"
	@echo "  $(CYAN)make clean$(RESET)     - Clean object files"
	@echo "  $(CYAN)make re$(RESET)        - Rebuild project"

check: all
	@echo "$(CYAN)$(BOLD)🔍 Running cppcheck...$(RESET)"
	@cppcheck --enable=all --check-level=exhaustive --suppress=missingIncludeSystem $(SRC_DIR)/*.c
	@echo "$(GREEN)✅ cppcheck completed!$(RESET)"

.PHONY: all clean fclean re gdb check help
