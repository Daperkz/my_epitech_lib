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
CFLAGS	:=	-I$(INCLUDE)
SRC	=	concat_params.c	\
		convert_base.c	\
		my_compute_power_rec.c	\
		my_compute_square_root.c	\
		my_find_prime_sup.c	\
		my_getnbr.c	\
		my_is_prime.c	\
		my_isneg.c	\
		my_put_nbr.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_show_word_array.c	\
		my_showmen.c	\
		my_showstr.c	\
		my_showstr.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_str_to_word_array.c	\
		my_strcapitalize.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strdup.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncat.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_strupcase.c	\
		my_swap.c	\

MYPRINTF_M	=	./my_printf/
OBJ	=	$(SRC:.c=.o)

.PHONY: fclean clean

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C $(MYPRINTF_M)
	ar -rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp $(HEADER) ../../include/

clean:
	rm -f $(OBJ)
	make clean -C $(MYPRINTF_M)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	make fclean -C $(MYPRINTF_M)

re: fclean $(NAME)

