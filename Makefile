##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Compil my_hunter
##

SRC	=	Src/main.c	\
		Src/manage_context.c	\
		Src/display.c	\
		Src/move_bird.c	\
		Src/shot.c	\
		Src/audio.c	\
		Src/destroy.c	\
		Src/menu.c	\
		Src/rules.c	\
		Src/pause.c

CC	=	gcc

CFLAGS	=	-I./include -Wall -Wextra -Werror

LDFLAGS =       -L. -lc_graph_prog

MYFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

all:	compil

compil:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

my:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(MYFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
