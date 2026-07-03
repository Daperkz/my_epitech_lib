##
## EPITECH PROJECT, 2026
## libdkz
## File description:
## test Makefile
##

NAME			=	unit_test
COVERAGE_NAME	=	gcov_result.txt

CC				=	clang
GCOVR			=	gcovr
VALGRIND		=	valgrind

# -_- DIRECTORIES -_-

REPO_D				=	../
ROOT_D				=	./
LIB_D				=	$(REPO_D)dkz/
TEST_D				=	$(REPO_D)test/

INCLUDE				=	$(LIB_D)include/
TEST_INCLUDE		=	$(TEST_D)include/

SRC_D				=	$(ROOT_D)src/
OBJ_D				=	$(ROOT_D)obj/

CONFIG_D			=	$(SRC_D)config/

FILE_D				=	$(SRC_D)file/

GRAPH_D				=	$(SRC_D)graph/
BTREE_D				=	$(GRAPH_D)binary/
DLL_D				=	$(GRAPH_D)double/
NODE_D				=	$(GRAPH_D)node/
LL_D				=	$(GRAPH_D)simple/

HASHTABLE_D			=	$(SRC_D)hashtable/

IO_D				=	$(SRC_D)io/

PRINTF_D			=	$(SRC_D)printf/
PRINTF_MODIFIERS_D	=	$(PRINTF_D)modifiers/
PRINTF_PARAMETERS_D	=	$(PRINTF_D)parameters/
PRINTF_UTILS_D		=	$(PRINTF_D)utils/

MATH_D				=	$(SRC_D)math/

STRING_D			=	$(SRC_D)string/
ARRAY_D				=	$(STRING_D)array/
COMPARAISON_D		=	$(STRING_D)comparaison/
CONVERT_D			=	$(STRING_D)convert/
MANIPULATION_D		=	$(STRING_D)manipulation/
SEARCH_D			=	$(STRING_D)search/

UTILS_D				=	$(SRC_D)utils/

WRAPPER_D			=	$(SRC_D)wrapper/

# -_- FLAGS -_-

CPPFLAGS		=	-I$(INCLUDE) -I$(TEST_INCLUDE)

CFLAGS			=	-O0 -Wall -Wextra --coverage -MMD -MP
CFLAGS_DEBUG	=	-g3 -O0

LDFLAGS_SPECIAL	=	-Wl,--wrap=malloc,--wrap=read,--wrap=stat
LDFLAGS			=	-lcriterion -L$(LIB_D) -ldkz $(LDFLAGS_SPECIAL)

GCOVR_FLAGS		=	--root $(REPO_D) 					\
					--filter $(LIB_D)src/ 				\
					--txt-metric branch 				\
					--gcov-executable "llvm-cov gcov"

VALGRIND_FLAGS	=	--leak-check=full		 			\
					--show-leak-kinds=definite 			\
					--errors-for-leak-kinds=definite 	\
					--suppressions=criterion.supp 		\
					--track-fds=yes


# -_- FILES -_-

SRC				=	$(CONFIG_D)test_create.c						\
					$(FILE_D)helpers.c								\
					$(FILE_D)test_get_file_content.c				\
					$(FILE_D)test_get_file_size.c					\
					$(FILE_D)test_open_file.c						\
					$(FILE_D)test_read_file.c						\
					$(BTREE_D)add.c									\
					$(BTREE_D)create.c								\
					$(BTREE_D)destroy.c								\
					$(BTREE_D)get.c									\
					$(DLL_D)add.c									\
					$(DLL_D)create.c								\
					$(DLL_D)destroy.c								\
					$(DLL_D)dump.c									\
					$(DLL_D)get.c									\
					$(DLL_D)pop.c									\
					$(NODE_D)create.c								\
					$(NODE_D)destroy.c								\
					$(LL_D)add.c									\
					$(LL_D)create.c									\
					$(LL_D)destroy.c								\
					$(LL_D)dump.c									\
					$(LL_D)get.c									\
					$(LL_D)pop.c									\
					$(HASHTABLE_D)test_bucket.c						\
					$(HASHTABLE_D)test_create.c						\
					$(HASHTABLE_D)test_destroy.c					\
					$(HASHTABLE_D)test_dump.c						\
					$(HASHTABLE_D)test_get.c						\
					$(HASHTABLE_D)test_hash.c						\
					$(HASHTABLE_D)test_insert.c						\
					$(HASHTABLE_D)test_pop.c						\
					$(IO_D)test_my_put_float.c						\
					$(IO_D)test_my_put_nbr.c						\
					$(IO_D)test_my_putchar.c						\
					$(IO_D)test_my_show_word_array.c				\
					$(IO_D)test_my_showmem.c						\
					$(IO_D)test_my_showstr.c						\
					$(PRINTF_MODIFIERS_D)test_precision.c 			\
					$(PRINTF_MODIFIERS_D)test_sharp.c 				\
					$(PRINTF_MODIFIERS_D)test_signs.c 				\
					$(PRINTF_MODIFIERS_D)test_width.c 				\
					$(PRINTF_PARAMETERS_D)test_parameter_a.c 		\
					$(PRINTF_PARAMETERS_D)test_parameter_chars.c	\
					$(PRINTF_PARAMETERS_D)test_parameter_e.c		\
					$(PRINTF_PARAMETERS_D)test_parameter_f.c		\
					$(PRINTF_PARAMETERS_D)test_parameter_g.c		\
					$(PRINTF_PARAMETERS_D)test_parameter_int.c		\
					$(PRINTF_PARAMETERS_D)test_parameter_n.c		\
					$(PRINTF_PARAMETERS_D)test_parameter_o.c		\
					$(PRINTF_PARAMETERS_D)test_parameter_p.c		\
					$(PRINTF_PARAMETERS_D)test_parameter_x.c		\
					$(PRINTF_UTILS_D)test_my_put_adress.c			\
					$(PRINTF_UTILS_D)test_my_put_float_hex.c		\
					$(PRINTF_UTILS_D)test_my_put_scientific.c		\
					$(PRINTF_D)test_my_printf.c						\
					$(PRINTF_D)test_parser.c						\
					$(MATH_D)test_macros.c							\
					$(MATH_D)test_my_compute_power_rec.c			\
					$(MATH_D)test_my_compute_square_root.c			\
					$(MATH_D)test_my_exp.c							\
					$(MATH_D)test_my_factorial.c					\
					$(MATH_D)test_my_find_prime_sup.c				\
					$(MATH_D)test_my_ipow.c							\
					$(MATH_D)test_my_is_prime.c						\
					$(MATH_D)test_my_isneg.c						\
					$(MATH_D)test_my_nbrlen.c						\
					$(MATH_D)test_my_rounds.c						\
					$(MATH_D)test_my_sign.c							\
					$(SRC_D)test_printf.c							\
					$(ARRAY_D)test_my_cpy_strarr.c					\
					$(ARRAY_D)test_my_free_strarr.c					\
					$(ARRAY_D)test_my_len_strarr.c					\
					$(ARRAY_D)test_my_put_strarr.c					\
					$(ARRAY_D)test_my_str_to_strarr_pairs.c			\
					$(ARRAY_D)test_my_str_to_strarr.c				\
					$(COMPARAISON_D)test_my_str_isalpha.c			\
					$(COMPARAISON_D)test_my_str_islower.c			\
					$(COMPARAISON_D)test_my_str_isnum.c				\
					$(COMPARAISON_D)test_my_str_isprintable.c		\
					$(COMPARAISON_D)test_my_str_isupper.c			\
					$(COMPARAISON_D)test_my_strcmp.c				\
					$(CONVERT_D)test_my_atof.c						\
					$(CONVERT_D)test_my_atoi.c						\
					$(CONVERT_D)test_my_ftoa.c						\
					$(CONVERT_D)test_my_itoab.c						\
					$(CONVERT_D)test_my_ltoab.c						\
					$(CONVERT_D)test_my_uitoab.c					\
					$(MANIPULATION_D)test_my_memcpy.c				\
					$(MANIPULATION_D)test_my_memmove.c				\
					$(MANIPULATION_D)test_my_memset.c				\
					$(MANIPULATION_D)test_my_putstr.c				\
					$(MANIPULATION_D)test_my_revstr.c				\
					$(MANIPULATION_D)test_my_strappend.c			\
					$(MANIPULATION_D)test_my_strcapitalize.c		\
					$(MANIPULATION_D)test_my_strcat.c				\
					$(MANIPULATION_D)test_my_strcpy.c				\
					$(MANIPULATION_D)test_my_strdup.c				\
					$(MANIPULATION_D)test_my_strjoin.c				\
					$(MANIPULATION_D)test_my_strlen.c				\
					$(MANIPULATION_D)test_my_strlowcase.c			\
					$(MANIPULATION_D)test_my_strtrim.c				\
					$(MANIPULATION_D)test_my_strupcase.c			\
					$(SEARCH_D)test_my_strchr.c						\
					$(SEARCH_D)test_my_strsep.c						\
					$(SEARCH_D)test_my_strstr.c						\
					$(UTILS_D)test_concat_params.c					\
					$(UTILS_D)test_convert_base.c					\
					$(UTILS_D)test_my_sort_int_array.c				\
					$(UTILS_D)test_my_swap.c						\
					$(WRAPPER_D)malloc_wrapper.c					\
					$(WRAPPER_D)read_wrapper.c						\
					$(WRAPPER_D)stat_wrapper.c

OBJ				=	$(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

DEPENDENCY		=	$(OBJ:%.o=%.d)

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(MAKE) -C $(LIB_D) tests --no-print-directory
	@$(CC) -o $@ $^ $(CPPFLAGS) $(CFLAGS) $(LDFLAGS)

$(OBJ_D)%.o:	$(SRC_D)%.c
	@mkdir -p $(dir $@)
	@$(CC) -o $@ -c $< $(CPPFLAGS) $(CFLAGS)

clean:
	@rm -rf $(OBJ_D)

fclean:
	@rm -rf $(OBJ_D)
	@rm -f $(NAME)
	@rm -f $(COVERAGE_NAME)

re: fclean $(NAME)

debug: CFLAGS += $(CFLAGS_DEBUG)
debug: $(NAME)

run:	$(NAME)
	@./$(NAME)
	@printf "\033[1;32m%s\033[0m\n" "Test ran."

memory_run:	debug
	@CRITERION_NO_FORK=1 $(VALGRIND) $(VALGRIND_FLAGS) ./$(NAME)

coverage:	fclean	run
	@$(GCOVR) $(GCOVR_FLAGS) > $(COVERAGE_NAME)
	@printf "\033[1;32m%s\033[0m\n" "Coverage Calculated."

memory_coverage: fclean memory_run
	@$(GCOVR) $(GCOVR_FLAGS) > $(COVERAGE_NAME)
	@printf "\033[1;32m%s\033[0m\n" "Coverage Calculated."

.PHONY: all fclean clean re run memory_run coverage memory_coverage
-include $(DEPENDENCY)
