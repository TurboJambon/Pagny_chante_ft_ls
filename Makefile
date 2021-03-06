# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/24 14:40:53 by dchirol           #+#    #+#              #
#    Updated: 2017/05/05 18:15:07 by dchirol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = 	ft_ls.c			parsing.c		errors.c	options.c		utilities.c	\
		others.c		display.c		buf.c		writebuf.c		date.c		\
		optionl.c		sorting.c 		optionu.c 	writebuf2.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@gcc -o $@ $^ libft.a

clean:
	/bin/rm -f $(OBJ)

fclean: clean


re : clean all