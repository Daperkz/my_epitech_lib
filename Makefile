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
	@$(MAKE) -C $(LIB_D) --no-print-directory

clean:
	@$(MAKE) -C $(LIB_D) clean --no-print-directory
	@$(MAKE) -C $(TEST_D) clean --no-print-directory

fclean:
	@$(MAKE) -C $(LIB_D) fclean --no-print-directory
	@$(MAKE) -C $(TEST_D) fclean --no-print-directory

re: fclean all

bestre:
	@$(MAKE) bestre -C $(LIB_D) --no-print-directory

test:
	@$(MAKE) -C $(TEST_D) --no-print-directory

test_run:
	@$(MAKE) run -C $(TEST_D) --no-print-directory

test_coverage:
	@$(MAKE) coverage -C $(TEST_D) --no-print-directory

.PHONY:	all	clean	fclean	re	bestre	test	test_run
