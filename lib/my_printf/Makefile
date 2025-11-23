##
## EPITECH PROJECT, 2025
## makefile
## File description:
## compiles for me
##

NAME	=	libmyprintf.a
CC	=	epiclang

INCLUDE	=	./include
HEADER	=	$(INCLUDE)/my_printf.h

CFLAGS	=	-I$(INCLUDE) -g3 -Wall -Wextra

SRC_F	=	./src/
BIN	=	./bin/

VPATH	=	$(SRC_F):$(UTILS_F):$(PARAM_F)

UTILS_F	=	$(SRC_F)utils/
MINILIB_SRC	=	$(UTILS_F)my_putchar.c \
				$(UTILS_F)my_putstr.c \
				$(UTILS_F)my_strlen.c \
				$(UTILS_F)my_put_nbr_base.c \
				$(UTILS_F)my_put_unsigned_nbr_base.c \
				$(UTILS_F)my_put_long_base.c \
				$(UTILS_F)my_put_float.c \
				$(UTILS_F)my_put_float_hex.c \
				$(UTILS_F)my_put_scientific.c \
				$(UTILS_F)my_put_adress.c \
				$(UTILS_F)my_strcpy.c \
				$(UTILS_F)my_strappend.c \
				$(UTILS_F)my_strcat.c

PARAM_F	=	$(SRC_F)parameters/
PARAM_SRC	=	$(PARAM_F)parameter_int.c \
				$(PARAM_F)parameter_o.c \
				$(PARAM_F)parameter_x.c \
				$(PARAM_F)parameter_f.c \
				$(PARAM_F)parameter_e.c \
				$(PARAM_F)parameter_g.c \
				$(PARAM_F)parameter_a.c \
				$(PARAM_F)parameter_chars.c \
				$(PARAM_F)parameter_p.c \
				$(PARAM_F)parameter_n.c \
				$(PARAM_F)error_output.c

SRC	=	$(SRC_F)my_printf.c	\
		$(SRC_F)switch_base_flag.c	\
		$(PARAM_SRC)	\
		$(MINILIB_SRC)

OBJ	=	$(addprefix $(BIN), $(notdir $(SRC:.c=.o)))

.PHONY:	fclean	clean	re

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $@ $^
	mv $@ ../
	cp $(HEADER) ../include

$(BIN)%.o:	%.c
	mkdir -p $(BIN)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../$(NAME)

re:	fclean	$(NAME)
