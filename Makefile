# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 11:23:05 by tlam              #+#    #+#              #
#    Updated: 2024/01/09 11:25:09 by tlam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

HEADER = so_long.h

SRC = main.c \
	get_next_line.c \
	get_next_line_utils.c \
	check_map.c \
	check_map2.c \
	utils.c \
	recursive.c \
	errors.c \
	movements.c \
	display_map.c \
	hooks.c \
	ft_printf/ft_itoa_printf.c \
	ft_printf/ft_printf.c \
	ft_printf/sources2_printf.c \
	ft_printf/sources_printf.c \

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT) :
		make -C $(LIBFT_PATH) all

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all : $(LIBFT_PATH) $(NAME)

clean :
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ)

fclean : clean
		make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re : fclean all

