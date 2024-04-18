# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 10:38:51 by rumachad          #+#    #+#              #
#    Updated: 2024/04/18 15:08:27 by rumachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC_PATH = src/
SRC = main.c \
	handle_events.c \
	math_v2D.c \
	init_v2D.c \
	load_image.c \
	clean.c

OBJ_PATH = obj/
OBJFILES = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJFILES))

CC = cc

MLX_HEADER = -I minilibx
MLX_PATH = minilibx-linux
LIBFT_PATH = libft

CFLAGS = -Wall -Wextra -Werrors -I include
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11
LIBFTFLAGS = -Llibft -lft

all: $(NAME)

$(NAME):	$(OBJ)
			make -C $(MLX_PATH)
			make -C $(LIBFT_PATH)
			$(CC) -o $(NAME) $(OBJ) $(MLXFLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(MLX_HEADER) -c $< -o $@

val: re
	valgrind --leak-check=full --show-leak-kinds=all ./cub3d

clean:
		make clean -C $(LIBFT_PATH)
		make clean -C $(MLX_PATH)
		rm -rf $(OBJ)

fclean: clean
		make fclean -C  $(LIBFT_PATH)
		rm -f $(NAME)

re: fclean all