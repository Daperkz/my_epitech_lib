##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## test Makefile
##

NAME	=	test_mylib
CC	=	epiclang

REPO_DIR	=	../
ROOT_DIR	=	./
LIB_DIR	=	$(REPO_DIR)my/
TEST_DIR	=	$(REPO_DIR)test/

INCLUDE	=	$(LIB_DIR)include/

CPPFLAGS	=	-I$(INCLUDE) -g3
CFLAGS	=	-Wall -Wextra
FLAGS_LIB	=	--coverage -fprofile-arcs -ftest-coverage
LDFLAGS	=	-lcriterion -L$(LIB_DIR) -lmy --coverage

COVERAGE_F	=	gcov_result.txt

SRC_D	=	$(ROOT_DIR)src/
OBJ_D	=	$(ROOT_DIR)obj/

SRC	=	$(addprefix $(SRC_D), test_io.c)	\
		$(addprefix $(SRC_D), test_string.c)	\
		$(addprefix $(SRC_D), test_utils.c)	\
		$(addprefix $(SRC_D), test_math.c)	\
		$(addprefix $(SRC_D), test_file.c)	\
		$(addprefix $(SRC_D), test_printf.c)	\
		$(addprefix $(SRC_D), test_graph.c)	\
		$(addprefix $(SRC_D), test_hashtable.c)	\
		$(addprefix $(SRC_D), test_config.c)

OBJ	=	$(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(MAKE) CFLAGS+="$(FLAGS_LIB)" -C $(LIB_DIR) --no-print-directory
	@$(CC) $^ -o $(NAME) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS)

$(OBJ_D)%.o:	$(SRC_D)%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@ $(CPPFLAGS) $(CFLAGS)

clean:
	@rm -rf $(OBJ_D)

fclean:
	@rm -rf $(OBJ_D)
	@rm -f $(NAME)
	@rm -f $(COVERAGE_F)

re: fclean $(NAME)

run:	$(NAME)
	@./$(NAME)
	@printf "\033[1;32m%s\033[0m\n" "Test ran."

coverage:	$(NAME)
	@./$(NAME)
	@touch $(COVERAGE_F)
	@gcovr --gcov-executable "llvm-cov gcov" --root $(REPO_DIR) --print-summary --filter $(LIB_DIR)src/ --exclude $(TEST_DIR) --branches > $(COVERAGE_F)
	@printf "\033[1;32m%s\033[0m\n" "Coverage Calculated."

.PHONY: all	fclean	clean	re	run	coverage
