##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## test Makefile
##

NAME			=	unit_test
COVERAGE_NAME	=	gcov_result.txt

CC				=	epiclang
GCOVR			=	gcovr

REPO_D			=	../
ROOT_D			=	./
LIB_D			=	$(REPO_D)my/
TEST_D			=	$(REPO_D)test/

INCLUDE			=	$(LIB_D)include/

SRC_D			=	$(ROOT_D)src/
OBJ_D			=	$(ROOT_D)obj/

CPPFLAGS		=	-I$(INCLUDE)
CFLAGS			=	-Wall -Wextra --coverage
LDFLAGS			=	-lcriterion -L$(LIB_D) -lmy

GCOVR_FLAGS		=	--root $(REPO_D) --filter $(LIB_D)src/ --txt-metric branch --gcov-executable "llvm-cov gcov"

SRC				=	$(SRC_D)test_io.c	\
					$(SRC_D)test_string.c	\
					$(SRC_D)test_utils.c	\
					$(SRC_D)test_math.c	\
					$(SRC_D)test_file.c	\
					$(SRC_D)test_printf.c	\
					$(SRC_D)test_graph.c	\
					$(SRC_D)test_hashtable.c	\
					$(SRC_D)test_config.c

OBJ				=	$(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

DEPENDENCY		=	$(OBJ:%.o=%.d)

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(MAKE) tests -C $(LIB_D) --no-print-directory
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

run:	$(NAME)
	@./$(NAME)
	@printf "\033[1;32m%s\033[0m\n" "Test ran."

coverage:	$(NAME)
	@./$(NAME)
	@$(GCOVR) $(GCOVR_FLAGS) > $(COVERAGE_NAME)
	@printf "\033[1;32m%s\033[0m\n" "Coverage Calculated."

.PHONY: all	fclean	clean	re	run	coverage
-include $(DEPENDENCY)
