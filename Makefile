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
	@$(MAKE) --no-print-directory -C $(LIB_D)

clean:
	@$(MAKE) --no-print-directory -C $(LIB_D) clean
	@$(MAKE) --no-print-directory -C $(TEST_D) clean

fclean:
	@$(MAKE) --no-print-directory -C $(LIB_D) fclean
	@$(MAKE) --no-print-directory -C $(TEST_D) fclean

re: fclean all

bestre:
	@$(MAKE) bestre --no-print-directory -C $(LIB_D)

test:
	@$(MAKE) --no-print-directory -C $(TEST_D)

test_run:
	@$(MAKE) run --no-print-directory -C $(TEST_D)

test_coverage:
	@$(MAKE) coverage --no-print-directory -C $(TEST_D)

.PHONY:	all	clean	fclean	re	bestre	test	test_run
