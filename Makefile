NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c ft_printf_util.c ft_hexas.c \

OBJ = $(SRC:.c=.o)

$(NAME):
	$(CC) $(FLAGS) -I./ -c $(SRC)
	ar -rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re