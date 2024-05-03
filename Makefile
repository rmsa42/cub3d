# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 10:38:51 by rumachad          #+#    #+#              #
#    Updated: 2024/05/03 16:41:49 by rumachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = cub3D

SRC_PATH = src/
VPATH = $(SRC_PATH) $(SRC_PATH)render $(SRC_PATH)raycasting $(SRC_PATH)map $(SRC_PATH)vector
SRC = main.c \
	handle_events.c \
	render.c \
	raycasting.c \
	init_map.c \
	map_draw.c \
	v2D_math.c \
	v2D_utils.c \
	load_image.c \
	parser.c \
	parser_utils.c \
	draw.c \
	clean.c

OBJ_PATH = obj/
OBJFILES = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJFILES))

CC = cc

MLX_HEADER = -I minilibx
MLX_PATH = minilibx-linux
LIBFT_PATH = libft

CFLAGS = -Wall -Wextra -Werror -I include
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11
LIBFTFLAGS = -Llibft -lft
MATHFLAGS = -lm

all: $(NAME)

$(NAME):	$(OBJ)
			@make -C $(MLX_PATH) > /dev/null 2>&1
			@echo "$(GREEN)MLX Compiled$(RESET)"
			@make -C $(LIBFT_PATH) > /dev/null
			@echo "$(GREEN)Libft Compiled$(RESET)"
			@$(CC) -o $(NAME) $(OBJ) $(MLXFLAGS) $(LIBFTFLAGS) $(MATHFLAGS)
			@echo "$(GREEN)Cub3d Compiled$(RESET)"

$(OBJ_PATH)%.o: %.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(MLX_HEADER) -c $< -o $@

val: re
	valgrind --leak-check=full --show-leak-kinds=all ./cub3D map.cub

clean:
		make clean -C $(LIBFT_PATH)
		make clean -C $(MLX_PATH)
		rm -rf $(OBJ)

fclean: clean
		@make fclean -C  $(LIBFT_PATH)
		rm -f $(NAME)

re: fclean all