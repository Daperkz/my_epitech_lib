##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## test Lakefile
##

NAME	=	test_mylib
CC	=	epiclang

REPO_DIR	=	../
ROOT_DIR	=	./
LIB_DIR	=	$(REPO_DIR)my/
TEST_DIR	=	$(REPO_DIR)test/

INCLUDE	=	$(LIB_DIR)include/

FLAGS_LIB	=	--coverage -fprofile-arcs -ftest-coverage
CFLAGS	=	-I$(INCLUDE) -Wall -Wextra -g3 -MMD -MP
LDFLAGS	=	-lcriterion -L$(LIB_DIR) -lmy --coverage

COVERAGE_F	=	gcov_result.txt

SRC_D	=	$(ROOT_DIR)src/
OBJ_D	=	$(ROOT_DIR)obj/

SRC	=	$(addprefix $(SRC_D), test_io.c)	\
		$(addprefix $(SRC_D), test_string.c)	\
		$(addprefix $(SRC_D), test_utils.c)	\
		$(addprefix $(SRC_D), test_math.c)	\
		$(addprefix $(SRC_D), test_file.c)	\

OBJ	=	$(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

DEP	=	$(OBJ:.o=.d)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) CFLAGS+="$(FLAGS_LIB)" -C $(LIB_DIR)
	$(CC) $^ -o $(NAME) $(CFLAGS) $(LDFLAGS)

$(OBJ_D):
	@mkdir -p $(OBJ_D)

$(OBJ_D)%.o:	$(SRC_D)%.c	|	$(OBJ_D)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(OBJ_D)

fclean:
	rm -rf $(OBJ_D)
	rm -f $(NAME)
	rm -f $(COVERAGE_F)

re: fclean $(NAME)

run:	$(NAME)
	-./$(NAME)

coverage:	run
	@touch $(COVERAGE_F)
	@gcovr --gcov-executable "llvm-cov gcov" --root $(REPO_DIR) --print-summary --filter $(LIB_DIR)src/ --exclude $(TEST_DIR) --branches > $(COVERAGE_F)

-include $(DEP)

.PHONY: all	fclean	clean	re	run	coverage
