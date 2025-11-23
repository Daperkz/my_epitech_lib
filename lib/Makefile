##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## lib makefile
##

NAME	=	libmy
CC	=	epiclang

ROOT_DIR	=	./
LIB_DIR	=	$(ROOT_DIR)my/

INCLUDE	=	$(ROOT_DIR)include/
LIB_INCLUDE	=	$(LIB_DIR)include/

HEADERS	=	$(LIB_INCLUDE)io_utils.h	\
			$(LIB_INCLUDE)string_utils.h	\
			$(LIB_INCLUDE)my_math.h	\
			$(LIB_INCLUDE)utils.h	\
			$(LIB_INCLUDE)my_printf.h	\
			$(LIB_INCLUDE)my.h	\

STATIC_LIB	=	$(LIB_DIR)$(NAME).a

.PHONY: fclean clean	re

all:	$(NAME)

$(NAME):
	make -C $(LIB_DIR)
	cp $(HEADERS) $(INCLUDE)
	cp $(STATIC_LIB) $(ROOT_DIR)

clean:
	make clean -C $(LIB_DIR)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -f libmy.a

re: fclean $(NAME)
