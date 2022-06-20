##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

NAME = ./mysh

SRC = 	source/minishell.c\
		source/read.c\
		source/read_next.c\
		source/command.c\
		source/tab.c\
		source/setenv.c\

all:
	make -C lib/my
	make -C lib/printf
	gcc -o $(NAME) $(SRC) -I include/ -L ./lib/my -lmy -L ./lib/printf -lprintf

clean:
	rm -f *~
	rm -f a.out
	rm -f vg*

fclean: clean
	make fclean -C lib/my
	make fclean -C lib/printf
	rm -f $(NAME)

re: fclean all

debug:
	make -C lib/my
	make -C lib/printf
	gcc -o $(NAME) $(SRC) -I include/ -L ./lib/my -lmy \
	-L ./lib/printf -lprintf -g3

norm:
	python -m normatrix
