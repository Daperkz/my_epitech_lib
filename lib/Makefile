##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## lib makefile
##

NAME	=	mylibs
CC	=	epiclang

LIB_MY	=	./my/
LIB_MY_PRINTF	=	./my_printf/

.PHONY: fclean clean	re

all:	$(NAME)

$(NAME):
	make -C $(LIB_MY)
	make -C $(LIB_MY_PRINTF)

clean:
	make clean -C $(LIB_MY)
	make clean -C $(LIB_MY_PRINTF)

fclean: clean
	make fclean -C $(LIB_MY)
	rm -f libmy.a
	make fclean -C $(LIB_MY_PRINTF)
	rm -f libmyprintf.a

re: fclean $(NAME)
