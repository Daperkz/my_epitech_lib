##
## EPITECH PROJECT, 2025
## makefile
## File description:
## compiles for me
##

NAME	=	libmy.a
CC	=	epiclang

INCLUDE	=	./include
HEADER = include/my.h

CFLAGS	:=	-I$(INCLUDE) -g3 -Wall -Wextra

BIN	=	./bin/
SRC_F	=	./src/

SRC	=	$(SRC_F)concat_params.c	\
		$(SRC_F)convert_base.c	\
		$(SRC_F)my_compute_power_rec.c	\
		$(SRC_F)my_compute_square_root.c	\
		$(SRC_F)my_find_prime_sup.c	\
		$(SRC_F)my_getnbr.c	\
		$(SRC_F)my_is_prime.c	\
		$(SRC_F)my_isneg.c	\
		$(SRC_F)my_put_nbr.c	\
		$(SRC_F)my_putchar.c	\
		$(SRC_F)my_putstr.c	\
		$(SRC_F)my_revstr.c	\
		$(SRC_F)my_show_word_array.c	\
		$(SRC_F)my_showmen.c	\
		$(SRC_F)my_showstr.c	\
		$(SRC_F)my_showstr.c	\
		$(SRC_F)my_str_isalpha.c	\
		$(SRC_F)my_str_islower.c	\
		$(SRC_F)my_str_isnum.c	\
		$(SRC_F)my_str_isprintable.c	\
		$(SRC_F)my_str_isupper.c	\
		$(SRC_F)my_str_to_word_array.c	\
		$(SRC_F)my_strcapitalize.c	\
		$(SRC_F)my_strcat.c	\
		$(SRC_F)my_strcmp.c	\
		$(SRC_F)my_strcpy.c	\
		$(SRC_F)my_strdup.c	\
		$(SRC_F)my_strlen.c	\
		$(SRC_F)my_strlowcase.c	\
		$(SRC_F)my_strncat.c	\
		$(SRC_F)my_strncpy.c	\
		$(SRC_F)my_strncmp.c	\
		$(SRC_F)my_strstr.c	\
		$(SRC_F)my_strupcase.c	\
		$(SRC_F)my_swap.c	\
		$(SRC_F)my_itoab.c	\

OBJ	=	$(addprefix $(BIN), $(notdir $(SRC:.c=.o)))

.PHONY:	fclean	clean	re

all:	$(NAME)

$(NAME):	$(OBJ)
	ar -rc $(NAME) $(OBJ)
	mv $(NAME) ../
	cp $(HEADER) ../include/

$(BIN)%.o:	$(SRC_F)%.c
	mkdir -p $(BIN)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re: fclean $(NAME)

