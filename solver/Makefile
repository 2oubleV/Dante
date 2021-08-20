##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## B-CPE-200-LIL-2-1-dante-antoine.podvin
##

SRC	=	src/main.c	\
        src/get_map.c   \
        src/solver.c    \
        src/get_shortest_path.c

NAME	=	solver

LIBRARY	=	-Llib/my -lmy

W_FLAGS	=	-W -Wall -Wextra

all:	$(NAME)

$(NAME):
	make -C ./lib/my
	gcc -o $(NAME) $(SRC) $(LIBRARY) $(W_FLAGS) -g

clean:
	rm -f libmy.a
	rm -f *.o
	rm -f *~
	rm -f *#
	rm -f lib/my/*.o

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re: fclean all
