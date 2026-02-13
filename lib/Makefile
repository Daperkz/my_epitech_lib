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
			$(LIB_INCLUDE)file_utils.h	\
			$(LIB_INCLUDE)my_printf.h	\
			$(LIB_INCLUDE)my.h	\

CFLAGS	=	-I$(LIB_INCLUDE) -I$(MY_PRINTF_INCLUDE) -g3 -Wall -Wextra

OBJ_D	=	$(LIB_DIR)obj/

SRC_D	=	$(LIB_DIR)src/

# -_- Directories located in $(SRC_D) = ./my/src/ -_-
IO_UTILS_D	=	$(SRC_D)io_utils/
STRING_UTILS_D	=	$(SRC_D)string_utils/
MATH_D	=	$(SRC_D)math/
UTILS_D	=	$(SRC_D)utils/
FILE_UTILS_D	=	$(SRC_D)file_utils/
MY_PRINTF_D	=	$(MY_PRINTF_DIR)src/

# -_- Directories located in $(STRING_UTILS_D) = ./my/src/string_utils/ -_-
WORD_ARRAY_D	=	$(STRING_UTILS_D)word_array/

# -_- Directories located in $(MY_PRINTF_D) = ./my/src/my_printf/src/ -_-
MY_PRINTF_UTILS_D	=	$(MY_PRINTF_D)utils/
MY_PRINTF_PARAM_D	=	$(MY_PRINTF_D)parameters/

# -_- Files located in $(IO_UTILS_D) = ./my/src/io_utils/ -_-
IO_UTILS_F	=	my_putchar.c	\
				my_put_nbr.c	\
				my_put_float.c	\
				my_showstr.c	\
				my_showmem.c	\
				my_show_word_array.c

# -_- Files located in $(STRING_UTILS_D) = ./my/src/string_utils/ -_-
STRING_UTILS_F	=	my_putstr.c	\
					my_strlen.c	\
					my_getnbr.c	\
					my_strcpy.c	\
					my_strncpy.c	\
					my_revstr.c	\
					my_strstr.c	\
					my_strchr.c	\
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
					my_strappend.c

# -_- Files located in $(WORD_ARRAY_D) = ./my/src/string_utils/word_array/ -_-
WORD_ARRAY_F	=	my_str_to_word_array.c	\
					my_print_word_array.c	\
					my_word_array_len.c	\
					my_copy_word_array.c	\
					my_free_word_array.c

# -_- Files located in $(MATH_D) = ./my/src/math/ -_-
MATH_F	=	my_isneg.c	\
			my_compute_power_rec.c	\
			my_compute_square_root.c	\
			my_is_prime.c	\
			my_find_prime_sup.c	\
			my_ipow.c	\
			my_factorial.c	\
			my_rounds.c	\
			my_nbrlen.c

# -_- Files located in $(UTILS_D) = ./my/src/utils/ -_-
UTILS_F	=	my_swap.c	\
			my_sort_int_array.c	\
			concat_params.c	\
			convert_base.c	\
			my_itoab.c	\
			my_uitoab.c	\
			my_ltoab.c	\
			my_ftoa.c

# -_- Files located in $(FILE_UTILS_D) = ./my/src/file_utils/ -_-
FILE_UTILS_F	=	open_file.c	\
					get_file_size.c	\
					get_file_content.c	\
					read_file.c

# -_- Files located in $(MY_PRINT_F) = ./my/src/my_printf/src -_-
MY_PRINTF_F	=	my_printf.c	\
				switch_base_flag.c

# -_- Files located in $(MY_PRINT_UTILS_D) = ./my/src/my_printf/src/utils/ -_-
MY_PRINTF_UTILS_F	=	my_put_float_hex.c \
						my_put_scientific.c \
						my_put_adress.c

# -_- Files located in $(MY_PRINT_PARAM_F) = ./my/src/my_printf/src/parameters/ -_-
MY_PRINTF_PARAM_F	=	parameter_int.c \
						parameter_o.c \
						parameter_x.c \
						parameter_f.c \
						parameter_e.c \
						parameter_g.c \
						parameter_a.c \
						parameter_chars.c \
						parameter_p.c \
						parameter_n.c

# -_- Files located in $(SRC_D) = ./my/src/ -_-
SRC	=	$(addprefix $(IO_UTILS_D), $(IO_UTILS_F)) 	\
		$(addprefix $(STRING_UTILS_D), $(STRING_UTILS_F))	\
		$(addprefix $(WORD_ARRAY_D), $(WORD_ARRAY_F))	\
		$(addprefix $(MATH_D), $(MATH_F))	\
		$(addprefix $(UTILS_D), $(UTILS_F))	\
		$(addprefix $(FILE_UTILS_D), $(FILE_UTILS_F))	\
		$(addprefix $(MY_PRINTF_D), $(MY_PRINTF_F))	\
		$(addprefix $(MY_PRINTF_UTILS_D), $(MY_PRINTF_UTILS_F))	\
		$(addprefix $(MY_PRINTF_PARAM_D), $(MY_PRINTF_PARAM_F))	\

# -_- puts all .c files wherever they come from into the bin folder as a .o -_-
OBJ	=	$(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

## --__-- RULES --__--

all:	$(NAME)

$(NAME):	$(OBJ)
	ar -rc $@ $^
	cp $(HEADERS) $(INCLUDE)

# -_- Creates the bin dir if non existent (only once) -_-
$(OBJ_D):
	mkdir -p $@

# -_- Compiles .o files into bin folder from all c files in the VPATH directories -_-
$(OBJ_D)%.o:	$(SRC_D)%.c | $(OBJ_D)
	@mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(OBJ_D)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bestre:
	make fclean
	make -j4

.PHONY:	all	clean	fclean	re	bestre
