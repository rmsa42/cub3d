# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 15:31:41 by rumachad          #+#    #+#              #
#    Updated: 2024/02/03 19:57:57 by rumachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LIBFT = libft
SRC_LIBFT = src/ft_isalnum.c src/ft_isalpha.c src/ft_isdigit.c \
		src/ft_isprint.c src/ft_isascii.c src/ft_strlen.c \
		src/ft_memset.c src/ft_bzero.c src/ft_strlcpy.c \
		src/ft_strlcat.c src/ft_toupper.c src/ft_tolower.c \
		src/ft_strchr.c src/ft_strrchr.c src/ft_atoi.c \
		src/ft_strncmp.c src/ft_memcpy.c src/ft_memchr.c \
		src/ft_memmove.c src/ft_strnstr.c \
		src/ft_calloc.c src/ft_strdup.c src/ft_substr.c \
		src/ft_strjoin.c src/ft_itoa.c src/ft_memcmp.c \
		src/ft_strtrim.c src/ft_putchar_fd.c src/ft_putstr_fd.c \
		src/ft_putendl_fd.c src/ft_putnbr_fd.c src/ft_striteri.c \
		src/ft_strmapi.c src/ft_split.c src/ft_printf.c src/ft_putchar.c \
		src/ft_putstr.c src/ft_putnbr.c src/ft_put_unsi_nbr.c src/ft_printhexa.c \
		src/ft_printhexa_upp.c src/ft_printpointer.c src/get_next_line.c \
		src/get_next_line_utils.c src/ft_lstnew.c src/ft_lstadd_front.c src/ft_lstsize.c \
		src/ft_lstlast.c src/ft_lstadd_back.c src/ft_lstdelone.c \
		src/ft_lstclear.c src/ft_lstiter.c src/ft_lstmap.c \
		src/ft_free_dp.c src/ft_strcmp.c \
		src_fprintf/ft_fprintf.c src_fprintf/ft_fprinthexa.c src_fprintf/ft_fprinthexa_upp.c \
		src_fprintf/ft_fprintpointer.c src_fprintf/ft_fput_unsi_nbr.c src_fprintf/ft_fputchar.c \
		src_fprintf/ft_fputnbr.c src_fprintf/ft_fputstr.c
OBJS_LIBFT = ${SRC_LIBFT:.c=.o}
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

%.o:%.c
		cc ${CFLAGS} -c $< -o $@

${NAME_LIBFT}:	${OBJS_LIBFT}
			ar rcs libft.a ${OBJS_LIBFT} libft.h

all:	${NAME_LIBFT}

clean:
		${RM} ${OBJS_LIBFT}

fclean: clean
		${RM} libft.a

re:	fclean ${NAME_LIBFT}

.PHONY:	all	clean fclean re