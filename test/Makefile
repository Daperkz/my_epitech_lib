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

REPO_D			=	../
ROOT_D			=	./
LIB_D			=	$(REPO_D)dkz/
TEST_D			=	$(REPO_D)test/

INCLUDE			=	$(LIB_D)include/
TEST_INCLUDE	=	$(TEST_D)include/

SRC_D			=	$(ROOT_D)src/
OBJ_D			=	$(ROOT_D)obj/

WRAPPER_D		=	$(SRC_D)wrapper/
STRING_D		=	$(SRC_D)string/
GRAPH_D			=	$(SRC_D)graph/


# -_- FLAGS -_-

CPPFLAGS		=	-I$(INCLUDE) -I$(TEST_INCLUDE)

CFLAGS			=	-O3 -Wall -Wextra --coverage -MMD -MP
CFLAGS_DEBUG	=	-g3

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

SRC				=	$(WRAPPER_D)malloc_wrapper.c	\
					$(WRAPPER_D)read_wrapper.c		\
					$(WRAPPER_D)stat_wrapper.c		\
					$(SRC_D)test_io.c				\
					$(STRING_D)test_array.c			\
					$(STRING_D)test_comparaison.c	\
					$(STRING_D)test_convert.c		\
					$(STRING_D)test_manipulation.c	\
					$(STRING_D)test_search.c		\
					$(SRC_D)test_utils.c			\
					$(SRC_D)test_math.c				\
					$(SRC_D)test_file.c				\
					$(SRC_D)test_printf.c			\
					$(GRAPH_D)test_bintree.c		\
					$(SRC_D)test_graph.c			\
					$(SRC_D)test_hashtable.c		\
					$(SRC_D)test_config.c

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
