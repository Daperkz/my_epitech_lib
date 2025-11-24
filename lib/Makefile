##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## lib makefile
##

NAME	=	libmy.a
CC	=	epiclang

ROOT_DIR	=	./
LIB_DIR	=	$(ROOT_DIR)my/
MY_PRINTF_DIR	=	$(LIB_DIR)src/my_printf/

# -_- Public include for my = ./my/src/my_printf/include -_-
INCLUDE	=	$(ROOT_DIR)include/
# -_- Internal include for my = ./my/src/my_printf/include -_-
LIB_INCLUDE	=	$(LIB_DIR)include/
# -_- Internal / Private include for my_printf = ./my/src/my_printf/include -_-
MY_PRINTF_INCLUDE	=	$(LIB_DIR)src/my_printf/include

HEADERS	=	$(LIB_INCLUDE)io_utils.h	\
			$(LIB_INCLUDE)string_utils.h	\
			$(LIB_INCLUDE)my_math.h	\
			$(LIB_INCLUDE)utils.h	\
			$(LIB_INCLUDE)my_printf.h	\
			$(LIB_INCLUDE)my.h	\

CFLAGS	=	-I$(LIB_INCLUDE) -I$(MY_PRINTF_INCLUDE) -g3 -Wall -Wextra

BIN_F	=	$(LIB_DIR)bin/

SRC_F	=	$(LIB_DIR)src/

# -_- Directories located in $(SRC_F) = ./my/src/ -_-
IO_UTILS_F	=	$(SRC_F)io_utils/
STRING_UTILS_F	=	$(SRC_F)string_utils/
MATH_F	=	$(SRC_F)math/
UTILS_F	=	$(SRC_F)utils/
MY_PRINTF_F	=	$(MY_PRINTF_DIR)src/

# -_- Directories located in $(MY_PRINTF_F) = ./my/src/my_printf/src/ -_-
MY_PRINTF_UTILS_F	=	utils/
MY_PRINTF_PARAM_F	=	parameters/

# -_- Files located in $(IO_UTILS_F) = ./my/src/io_utils/ -_-
IO_UTILS	=	my_putchar.c	\
				my_put_nbr.c	\
				my_put_float.c	\
				my_showstr.c	\
				my_showmem.c	\
				my_show_word_array.c

# -_- Files located in $(STRING_UTILS_F) = ./my/src/string_utils/ -_-
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

# -_- Files located in $(MATH_F) = ./my/src/math/ -_-
MATH	=	my_isneg.c	\
			my_compute_power_rec.c	\
			my_compute_square_root.c	\
			my_is_prime.c	\
			my_find_prime_sup.c	\
			my_ipow.c	\
			my_nbrlen.c

# -_- Files located in $(UTILS_F) = ./my/src/utils/ -_-
UTILS	=	my_swap.c	\
			my_sort_int_array.c	\
			concat_params.c	\
			convert_base.c	\
			my_itoab.c	\
			my_uitoab.c	\
			my_ltoab.c	\
			my_ftoa.c


# -_- Files located in $(MY_PRINT_UTILS_F) = ./my/src/my_printf/src/utils/ -_-
MY_PRINTF_UTILS	=	my_put_float_hex.c \
					my_put_scientific.c \
					my_put_adress.c

# -_- Files located in $(MY_PRINT_PARAM_F) = ./my/src/my_printf/src/parameters/ -_-
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

# -_- Files located in $(MY_PRINT_F) = ./my/src/my_printf/src -_-
MY_PRINTF	=	my_printf.c	\
				switch_base_flag.c	\
				$(patsubst %.c, $(MY_PRINTF_UTILS_F)%.c, $(MY_PRINTF_UTILS)) 	\
				$(patsubst %.c, $(MY_PRINTF_PARAM_F)%.c, $(MY_PRINTF_PARAM))

# -_- Files located in $(SRC_F) = ./my/src/ -_-
SRC	=	$(patsubst %.c, $(IO_UTILS_F)%.c, $(IO_UTILS)) 	\
		$(patsubst %.c, $(STRING_UTILS_F)%.c, $(STRING_UTILS))	\
		$(patsubst %.c, $(MATH_F)%.c, $(MATH))	\
		$(patsubst %.c, $(UTILS_F)%.c, $(UTILS))	\
		$(patsubst %.c, $(MY_PRINTF_F)%.c, $(MY_PRINTF))	\

# -_- puts all .c files wherever they come from into the bin folder as a .o -_-
OBJ	=	$(addprefix $(BIN_F), $(notdir $(SRC:.c=.o)))

# -_- All src files directories (where to find them) -_-
VPATH	=	$(SRC_F)	\
			$(IO_UTILS_F) $(STRING_UTILS_F) $(MATH_F) $(UTILS_F) \
			$(MY_PRINTF_F) \
			$(MY_PRINTF_F)$(MY_PRINTF_UTILS_F) $(MY_PRINTF_F)$(MY_PRINTF_PARAM_F)


.PHONY:	all	clean	fclean	re	bestre

all:	$(NAME)


$(NAME):	$(OBJ)
	ar -rc $@ $^
	cp $(HEADERS) $(INCLUDE)

# -_- Creates the bin dir if non existent (only once) -_-
$(BIN_F):
	mkdir -p $@

# -_- Compiles .o files into bin folder from all c files in the VPATH directories -_-
$(BIN_F)%.o:	%.c | $(BIN_F)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)
	-rmdir $(BIN_F)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bestre:
	make fclean
	make -j4
