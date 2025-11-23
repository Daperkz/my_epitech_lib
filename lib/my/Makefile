##
## EPITECH PROJECT, 2025
## makefile
## File description:
## compiles for me
##

NAME	=	libmy.a
CC	=	epiclang

INCLUDE	=	./include/
HEADER	=	$(INCLUDE)my.h	\
			$(INCLUDE)io_utils.h	\
			$(INCLUDE)string_utils.h	\
			$(INCLUDE)my_math.h	\
			$(INCLUDE)utils.h	\

CFLAGS	:=	-I$(INCLUDE) -g3 -Wall -Wextra

BIN	=	./bin/
SRC_F	=	./src/

IO_UTILS_F	=	$(SRC_F)io_utils/
IO_UTILS	=	$(IO_UTILS_F)my_putchar.c	\
				$(IO_UTILS_F)my_put_nbr.c	\
				$(IO_UTILS_F)my_showstr.c	\
				$(IO_UTILS_F)my_showmen.c	\
				$(IO_UTILS_F)my_show_word_array.c

STRING_UTILS_F	=	$(SRC_F)string_utils/
STRING_UTILS	=	$(STRING_UTILS_F)my_putstr.c	\
					$(STRING_UTILS_F)my_strlen.c	\
					$(STRING_UTILS_F)my_getnbr.c	\
					$(STRING_UTILS_F)my_strcpy.c	\
					$(STRING_UTILS_F)my_strncpy.c	\
					$(STRING_UTILS_F)my_revstr.c	\
					$(STRING_UTILS_F)my_strstr.c	\
					$(STRING_UTILS_F)my_strcmp.c	\
					$(STRING_UTILS_F)my_strncmp.c	\
					$(STRING_UTILS_F)my_strupcase.c	\
					$(STRING_UTILS_F)my_strlowcase.c	\
					$(STRING_UTILS_F)my_strcapitalize.c	\
					$(STRING_UTILS_F)my_str_isalpha.c	\
					$(STRING_UTILS_F)my_str_isnum.c	\
					$(STRING_UTILS_F)my_str_islower.c	\
					$(STRING_UTILS_F)my_str_isupper.c	\
					$(STRING_UTILS_F)my_str_isprintable.c	\
					$(STRING_UTILS_F)my_strcat.c	\
					$(STRING_UTILS_F)my_strncat.c	\
					$(STRING_UTILS_F)my_strdup.c	\
					$(STRING_UTILS_F)my_str_to_word_array.c	\
					$(STRING_UTILS_F)my_strappend.c	\

MATH_F	=	$(SRC_F)math/
MATH	=	$(MATH_F)my_isneg.c	\
			$(MATH_F)my_compute_power_rec.c	\
			$(MATH_F)my_compute_square_root.c	\
			$(MATH_F)my_is_prime.c	\
			$(MATH_F)my_find_prime_sup.c	\
			$(MATH_F)my_ipow.c	\

UTILS_F	=	$(SRC_F)utils/
UTILS	=	$(UTILS_F)my_swap.c	\
			$(UTILS_F)my_sort_int_array.c	\
			$(UTILS_F)concat_params.c	\
			$(UTILS_F)convert_base.c	\
			$(UTILS_F)my_itoab.c	\
			$(UTILS_F)my_ftoa.c	\

SRC	=	$(IO_UTILS)	\
		$(STRING_UTILS)	\
		$(MATH)	\
		$(UTILS)	\

OBJ	=	$(addprefix $(BIN), $(notdir $(SRC:.c=.o)))

VPATH	=	$(SRC_F):$(IO_UTILS_F):$(STRING_UTILS_F):$(MATH_F):$(UTILS_F)

.PHONY:	fclean	clean	re

all:	$(NAME)

$(NAME):	$(OBJ)
	ar -rc $(NAME) $(OBJ)
	mv $(NAME) ../
	cp $(HEADER) ../include/

$(BIN)%.o:	%.c
	mkdir -p $(BIN)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re: fclean $(NAME)

