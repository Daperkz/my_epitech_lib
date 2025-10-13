##
## EPITECH PROJECT, 2025
## makefile
## File description:
## compiles for me
##

NAME	=	libmy.a
CC	=	clang
INCLUDE	=	./include
HEADER = include/my.h
CFLAGS	:=	-I$(INCLUDE)
SRC	=	$(wildcard *.c)
OBJ	=	$(SRC:.c=.o)

.PHONY: fclean clean

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	make copymoove

copymoove:
	cp $(NAME) ../
	cp $(HEADER) ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

