##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## lib makefile
##

NAME	=	test_mylib
CC	=	epiclang

LIB_F	=	../lib/
INCLUDE	=	$(LIB_F)include/

CFLAGS	=	-I$(INCLUDE)
LDFLAGS	=	-lcriterion -L$(LIB_F) -lmy

SRC_F	=	./src/
SRC	=	test_my.c

BIN	=	./bin/

OBJ	=	$(addprefix $(BIN), $(notdir $(SRC:.c=.o)))

VPATH	=	$(SRC_F)

.PHONY: fclean clean	re	run_tests

all:	$(NAME)


$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS)

$(BIN)%.o:	%.c
	mkdir -p $(BIN)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)
	rmdir $(BIN)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

run_tests:	$(NAME)
	./$(NAME)
