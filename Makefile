# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 10:38:51 by rumachad          #+#    #+#              #
#    Updated: 2024/05/10 11:42:28 by rumachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = cub3D
BONUS = cub3D_bonus

SRC_BONUS_PATH = src_bonus/
SRC_PATH = src/
VPATH = $(SRC_PATH) $(SRC_PATH)render $(SRC_PATH)raycasting $(SRC_PATH)map $(SRC_PATH)vector \
		$(SRC_BONUS_PATH) $(SRC_BONUS_PATH)render $(SRC_BONUS_PATH)raycasting $(SRC_BONUS_PATH)map $(SRC_BONUS_PATH)vector
SRC_BONUS = main_bonus.c \
	handle_events_bonus.c \
	render_bonus.c \
	raycasting_bonus.c \
	init_map_bonus.c \
	map_draw_bonus.c \
	v2D_math_bonus.c \
	v2D_utils_bonus.c \
	load_image_bonus.c \
	parser_bonus.c \
	parser_utils_bonus.c \
	read_from_file_bonus.c \
	check_b4_init_bonus.c \
	draw_bonus.c \
	clean_bonus.c 

SRC = main.c \
	handle_events.c \
	render.c \
	raycasting.c \
	texture_pos.c \
	init_map.c \
	map_draw.c \
	check_map.c \
	v2D_math.c \
	v2D_utils.c \
	load_image.c \
	check_functions.c \
	utils.c \
	read_from_file.c \
	check_b4_init.c \
	draw.c \
	clean.c

OBJ_BONUS_PATH = obj_bonus/
OBJ_BONUS_FILES = $(SRC_BONUS:.c=.o)
OBJ_BONUS = $(addprefix $(OBJ_BONUS_PATH), $(OBJ_BONUS_FILES))

OBJ_PATH = obj/
OBJFILES = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJFILES))

CC = cc

MLX_HEADER = -I minilibx
MLX_PATH = minilibx-linux
LIBFT_PATH = libft

HEADER = include
HEADER_BONUS = include_bonus
CFLAGS = -Wall -Wextra -Werror -I
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

$(BONUS):	$(OBJ_BONUS)
			@make -C $(MLX_PATH) > /dev/null 2>&1
			@echo "$(GREEN)MLX Compiled$(RESET)"
			@make -C $(LIBFT_PATH) > /dev/null
			@echo "$(GREEN)Libft Compiled$(RESET)"
			@$(CC) -o $(BONUS) $(OBJ_BONUS) $(MLXFLAGS) $(LIBFTFLAGS) $(MATHFLAGS)
			@echo "$(GREEN)Cub3d Bonus Compiled$(RESET)"

$(OBJ_PATH)%.o: %.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(HEADER) $(MLX_HEADER) -c $< -o $@

$(OBJ_BONUS_PATH)%.o: %.c
	@mkdir -p $(OBJ_BONUS_PATH)
	@$(CC) $(CFLAGS) $(HEADER_BONUS) $(MLX_HEADER) -c $< -o $@

val: re
	valgrind --leak-check=full --show-leak-kinds=all ./cub3D map.cub

bonus: $(BONUS)

clean:
		@make clean -C $(LIBFT_PATH) > /dev/null
		@make clean -C $(MLX_PATH) > /dev/null 2>&1
		@rm -rf $(OBJ) $(OBJ_BONUS) > /dev/null

fclean: clean
		@make fclean -C  $(LIBFT_PATH) > /dev/null
		@rm -f $(NAME) $(BONUS)
		@echo "$(GREEN)Objects cleaned$(RESET)"

re: fclean all