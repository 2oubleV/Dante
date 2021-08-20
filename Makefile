##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## B-CPE-200-LIL-2-1-dante-antoine.podvin
##

all:
	make -C ./generator
	make -C ./solver

clean:
	make clean -C ./generator
	make clean -C ./solver

fclean: clean
	make fclean -C ./generator
	make fclean -C ./solver

re: fclean all
