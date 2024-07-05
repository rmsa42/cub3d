# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 10:38:51 by rumachad          #+#    #+#              #
#    Updated: 2024/07/05 10:14:09 by rumachad         ###   ########.fr        #
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
		$(SRC_BONUS_PATH) $(SRC_BONUS_PATH)render $(SRC_BONUS_PATH)raycasting \
		$(SRC_BONUS_PATH)map $(SRC_BONUS_PATH)vector $(SRC_BONUS_PATH)events \
		$(SRC_BONUS_PATH)parser $(SRC_BONUS_PATH)draw

SRC_BONUS = main_bonus.c \
	game_loop_bonus.c \
	handle_events_bonus.c \
	update_player_bonus.c \
	update_ball_bonus.c \
	update_sprites_bonus.c \
	update_animations_bonus.c \
	raycasting_bonus.c \
	ray_hit_bonus.c \
	enemy_raycast_bonus.c \
	init_sprites_bonus.c \
	init_structs_bonus.c \
	set_map_bonus.c \
	v2D_math_bonus.c \
	v2D_utils_bonus.c \
	img_manipulation_bonus.c \
	map_parser_bonus.c \
	create_content_map_bonus.c \
	create_full_map_bonus.c \
	check_elements_bonus.c \
	parser_utils_bonus.c \
	flood_fill_bonus.c \
	draw_bonus.c \
	draw_sprite_bonus.c \
	draw_hud_bonus.c \
	draw_extra_bonus.c \
	draw_minimap_bonus.c \
	sort_sprites.c \
	line_calcs_bonus.c \
	clean_bonus.c \
	free_mem_bonus.c \
	destructors_bonus.c \
	common_bonus.c \
	check_objs_bonus.c \
	raycaster_help_bonus.c \
	ball_hits_bonus.c \
	put_tile_bonus.c \
	player_inter_bonus.c

SRC = main.c \
	handle_events.c \
	img_manipulation.c \
	raycasting.c \
	texture_pos.c \
	map_parser.c \
	create_content_map.c \
	create_full_map.c \
	flood_fill.c \
	parser_utils.c \
	set_map.c \
	v2D_math.c \
	v2D_utils.c \
	check_functions.c \
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
CFLAGS = -O3 -Wall -Wextra -Werror -I
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11
LIBFTFLAGS = -Llibft -lft
MATHFLAGS = -lm

all: $(NAME)

$(NAME):	$(OBJ)
			@rm -rf $(OBJ_BONUS_PATH)
			@make -C $(MLX_PATH) > /dev/null 2>&1
			@echo "$(GREEN)MLX Compiled$(RESET)"
			@make -C $(LIBFT_PATH) > /dev/null
			@echo "$(GREEN)Libft Compiled$(RESET)"
			@$(CC) -o $(NAME) $(OBJ) $(MLXFLAGS) $(LIBFTFLAGS) $(MATHFLAGS)
			@echo "$(GREEN)Cub3d Compiled$(RESET)"


$(BONUS):	$(OBJ_BONUS)
			@rm -rf $(OBJ_PATH)
			@make -C $(MLX_PATH) > /dev/null 2>&1
			@echo "$(GREEN)MLX Compiled$(RESET)"
			@make -C $(LIBFT_PATH) > /dev/null
			@echo "$(GREEN)Libft Compiled$(RESET)"
			@$(CC) -o $(NAME) $(OBJ_BONUS) $(MLXFLAGS) $(LIBFTFLAGS) $(MATHFLAGS)
			@echo "$(GREEN)Cub3d Bonus Compiled$(RESET)"

$(OBJ_PATH)%.o: %.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(HEADER) $(MLX_HEADER) -c $< -o $@

$(OBJ_BONUS_PATH)%.o: %.c
	@mkdir -p $(OBJ_BONUS_PATH)
	@$(CC) $(CFLAGS) $(HEADER_BONUS) $(MLX_HEADER) -c $< -o $@

bonus: $(BONUS)

clean:
		@make clean -C $(LIBFT_PATH) > /dev/null
		@make clean -C $(MLX_PATH) > /dev/null 2>&1
		@rm -rf $(OBJ_PATH) $(OBJ_BONUS_PATH) > /dev/null

fclean: clean
		@make fclean -C  $(LIBFT_PATH) > /dev/null
		@rm -f $(NAME)
		@echo "$(GREEN)Objects cleaned$(RESET)"

re: fclean all