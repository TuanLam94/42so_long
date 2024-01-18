# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 11:51:58 by tlam              #+#    #+#              #
#    Updated: 2023/12/04 12:22:48 by tlam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h \
	 ft_printf.h \

SRC =	ft_atoi.c \
                ft_bzero.c \
                ft_calloc.c \
                ft_isalnum.c \
                ft_isalpha.c \
                ft_isascii.c \
                ft_isdigit.c \
                ft_isprint.c \
		ft_itoa.c \
                ft_memchr.c \
                ft_memcmp.c \
                ft_memcpy.c \
                ft_memmove.c \
                ft_memset.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_split.c \
                ft_strchr.c \
                ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
                ft_strlcat.c \
                ft_strlcpy.c \
                ft_strlen.c \
		ft_strmapi.c \
                ft_strncmp.c \
                ft_strnstr.c \
                ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
                ft_tolower.c \
                ft_toupper.c \
		ft_itoa_printf.c \
		ft_printf.c \
		sources_printf.c \
		sources2_printf.c \
		ft_lstadd_back.c \
	    	ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)  

.c.o :
	$(CC) $(CFLAGS) -I. -c $< -o $(<:.c=.o)

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

