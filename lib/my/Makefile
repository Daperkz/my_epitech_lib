##
## EPITECH PROJECT, 2025
## makefile
## File description:
## compiles for me
##

NAME	=	libmy.a
CC	=	epiclang

ROOT_DIR	=	./

# --- Public include for my_printf = ./src/my_printf/include ---
INCLUDE	=	$(ROOT_DIR)include/

# --- Internal / Private include for my_printf = ./src/my_printf/include ---
MY_PRINTF_INCLUDE	=	$(ROOT_DIR)src/my_printf/include

CFLAGS	=	-I$(INCLUDE) -I$(MY_PRINTF_INCLUDE) -g3 -Wall -Wextra

BIN	=	$(ROOT_DIR)bin/

SRC_F	=	$(ROOT_DIR)src/

IO_UTILS_F	=	$(SRC_F)io_utils/
STRING_UTILS_F	=	$(SRC_F)string_utils/
MATH_F	=	$(SRC_F)math/
UTILS_F	=	$(SRC_F)utils/

MY_PRINTF_F	=	$(SRC_F)my_printf/src/
# --- Directories located in $(MY_PRINTF_F) = ./src/my_printf/src/ ---
MY_PRINTF_UTILS_F	=	utils/
MY_PRINTF_PARAM_F	=	parameters/

# --- Files located in $(IO_UTILS_F) = ./src/io_utils/ ---
IO_UTILS	=	my_putchar.c	\
				my_put_nbr.c	\
				my_showstr.c	\
				my_showmem.c	\
				my_show_word_array.c

# --- Files located in $(STRING_UTILS_F) = ./src/string_utils/ ---
STRING_UTILS	=	my_putstr.c	\
					my_strlen.c	\
					my_getnbr.c	\
					my_strcpy.c	\
					my_strncpy.c	\
					my_revstr.c	\
					my_strstr.c	\
					my_strcmp.c	\
					my_strncmp.c	\
					my_strupcase.c	\
					my_strlowcase.c	\
					my_strcapitalize.c	\
					my_str_isalpha.c	\
					my_str_isnum.c	\
					my_str_islower.c	\
					my_str_isupper.c	\
					my_str_isprintable.c	\
					my_strcat.c	\
					my_strncat.c	\
					my_strdup.c	\
					my_str_to_word_array.c	\
					my_strappend.c

# --- Files located in $(MATH_F) = ./src/math/ ---
MATH	=	my_isneg.c	\
			my_compute_power_rec.c	\
			my_compute_square_root.c	\
			my_is_prime.c	\
			my_find_prime_sup.c	\
			my_ipow.c	\
			my_nbrlen.c

# --- Files located in $(UTILS_F) = ./src/utils/ ---
UTILS	=	my_swap.c	\
			my_sort_int_array.c	\
			concat_params.c	\
			convert_base.c	\
			my_itoab.c	\
			my_uitoab.c	\
			my_ltoab.c	\
			my_ftoa.c


# --- Files located in $(MY_PRINT_UTILS_F) = ./src/my_printf/src/utils/ ---
MY_PRINTF_UTILS	=	my_put_float_hex.c \
					my_put_scientific.c \
					my_put_adress.c

# --- Files located in $(MY_PRINT_PARAM_F) = ./src/my_printf/src/parameters/ ---
MY_PRINTF_PARAM	=	parameter_int.c \
					parameter_o.c \
					parameter_x.c \
					parameter_f.c \
					parameter_e.c \
					parameter_g.c \
					parameter_a.c \
					parameter_chars.c \
					parameter_p.c \
					parameter_n.c

# --- Files located in $(MY_PRINT_F) = ./src/my_printf/src ---
MY_PRINTF	=	my_printf.c	\
				switch_base_flag.c	\
				$(patsubst %.c, $(MY_PRINTF_UTILS_F)%.c, $(MY_PRINTF_UTILS)) 	\
				$(patsubst %.c, $(MY_PRINTF_PARAM_F)%.c, $(MY_PRINTF_PARAM))

# --- Files located in $(SRC_F) = ./src/ ---
SRC	=	$(patsubst %.c, $(IO_UTILS_F)%.c, $(IO_UTILS)) 	\
		$(patsubst %.c, $(STRING_UTILS_F)%.c, $(STRING_UTILS))	\
		$(patsubst %.c, $(MATH_F)%.c, $(MATH))	\
		$(patsubst %.c, $(UTILS_F)%.c, $(UTILS))	\
		$(patsubst %.c, $(MY_PRINTF_F)%.c, $(MY_PRINTF))	\

OBJ	=	$(addprefix $(BIN), $(notdir $(SRC:.c=.o)))

VPATH	=	$(SRC_F) $(IO_UTILS_F) $(STRING_UTILS_F) $(MATH_F) $(UTILS_F) $(MY_PRINTF_F) $(MY_PRINTF_F)$(MY_PRINTF_UTILS_F) $(MY_PRINTF_F)$(MY_PRINTF_PARAM_F)

.PHONY:	fclean	clean	re

all:	$(NAME)

$(NAME):	$(OBJ)
	ar -rc $@ $^

$(BIN)%.o:	%.c
	mkdir -p $(BIN)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

