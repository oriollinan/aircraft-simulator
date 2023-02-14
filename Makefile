##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## building and cleaning a library
##

SRC = 	src/system/my_radar.c \
		src/system/error_handling.c \
		src/system/file.c \
		src/system/clock.c \
		src/system/system.c \
		src/system/game/plane.c \
		src/system/game/tower.c \
		src/system/game/window.c \
		src/system/game/events.c \
		src/system/game/rectangle.c \
		src/system/game/game.c \
		src/system/game/entity.c \
		src/system/game/circle.c \
		src/system/game/text.c \
		src/OOP/new.c

# find -wholename ".*.h" | cut -d "/" -f2-

OBJ =	$(SRC:.c=.o)

NAME =  my_radar

CFLAGS = -I./include/my_radar/ -I./include/ -g3

LFLAGS = -L./lib/

LDLIBS = -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm

LIBS = -lstr -lnum -larr

LIB = lib/

all:    $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	gcc -o $(NAME) $(OBJ) $(LFLAGS) $(LDLIBS) $(LIBS)

clean:
	rm -f $(OBJ)
	make clean -C $(LIB)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIB)

re:	fclean all
