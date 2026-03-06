##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## Root Makefile
##


ROOT_DIR	=	./

LIB_D	=	$(ROOT_DIR)my/
TEST_D	=	$(ROOT_DIR)test/

all:
	@$(MAKE) -C $(LIB_D)

clean:
	@$(MAKE) -C $(LIB_D) clean
	@$(MAKE) -C $(TEST_D) clean

fclean:
	@$(MAKE) -C $(LIB_D) fclean
	@$(MAKE) -C $(TEST_D) fclean

re: fclean all

test:
	@$(MAKE) -C $(TEST_D)

test_run:	test
	@$(MAKE) run -C $(TEST_D)

.PHONY:	all	clean	fclean	re	test	test_run
