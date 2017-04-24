# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niragne <niragne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 17:19:21 by niragne           #+#    #+#              #
#    Updated: 2017/02/12 16:35:56 by niragne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_putchar.c \
	  ft_putstr.c \
	  ft_strcmp.c \
	  ft_strlen.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_memset.c \
	  ft_memalloc.c \
	  ft_putendl.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_bzero.c \
	  ft_strnew.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_putnbr.c \
	  ft_itoa.c \
	  ft_isprint.c \
	  ft_isalpha.c \
	  ft_isalnum.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_memdel.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncmp.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_memcmp.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strnstr.c \
	  ft_isspace.c \
	  ft_atoi.c \
	  ft_memmove.c \
	  ft_memccpy.c \
	  ft_memcpy.c \
	  ft_memchr.c \
	  ft_itoa.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstiter.c \
	  ft_newpoint.c \
	  ft_get_middle.c \
	  ft_lstmap.c \
	  ft_newvector.c \
	  ft_translation.c \
	  ft_getvector.c \
	  ft_isupper.c \
	  ft_islower.c \
	  ft_lstadd.c \
	  ft_range.c \
	  ft_tablen.c \
	  ft_sort_tab.c \
	  ft_putarr.c \
	  ft_freearr.c \
	  ft_sqrt.c \
	  ft_strtoupper.c \
	  ft_strtolower.c \
	  ft_swap.c \
	  ft_foreach.c \
	  ft_rot.c \
	  ft_iscollinear.c \
	  fd_to_str.c \
	  ft_realloc.c \
	  get_next_line.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -Werror -Wextra -Wall -c $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
