NAME = ft_ls

SRC = ft_ls.c parsing.c errors.c options.c utilities.c others.c display.c buf.c writebuf.c date.c

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