##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## building and cleaning a library
##

SRC =	$(wildcard *.c)

OBJ =	$(SRC:.c=.o)

NAME =  libarr.a

CFLAGS = -I./../../include -g3

BACK = ../

all:    $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) $(BACK)$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(BACK)$(NAME)

re:	fclean all
