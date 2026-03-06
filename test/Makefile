##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## test Lakefile
##

NAME	=	test_mylib
CC	=	epiclang

ROOT_DIR	=	./
LIB_DIR	=	../my/

INCLUDE	=	$(LIB_DIR)include/

CFLAGS	=	-I$(INCLUDE) -g3
LDFLAGS	=	-lcriterion -L$(LIB_DIR) -lmy

SRC_D	=	$(ROOT_DIR)src/
OBJ_D	=	$(ROOT_DIR)obj/


SRC	=	$(addprefix $(SRC_D), test_io.c)	\

OBJ	=	$(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $^ -o $(NAME) $(CFLAGS) $(LDFLAGS)

$(OBJ_D):
	@mkdir -p $(OBJ_D)

$(OBJ_D)%.o:	$(SRC_D)%.c	|	$(OBJ_D)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(MAKE) clean -C $(LIB_DIR)
	rm -rf $(OBJ_D)

fclean:
	$(MAKE) fclean -C $(LIB_DIR)
	rm -rf $(OBJ_D)
	rm -f $(NAME)

re: fclean $(NAME)

run:	$(NAME)
	./$(NAME)

.PHONY: all	fclean clean	re	run
