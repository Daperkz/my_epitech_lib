##
## EPITECH PROJECT, 2026
## libdkz
## File description:
## Root Makefile
##


ROOT_D	=	./

LIB_D	=	$(ROOT_D)dkz/
TEST_D	=	$(ROOT_D)test/

all:
	@$(MAKE) -C $(LIB_D) --no-print-directory

debug:
	@$(MAKE) debug -C $(LIB_D) --no-print-directory

clean:
	@$(MAKE) -C $(LIB_D) clean --no-print-directory
	@$(MAKE) -C $(TEST_D) clean --no-print-directory

fclean:
	@$(MAKE) -C $(LIB_D) fclean --no-print-directory
	@$(MAKE) -C $(TEST_D) fclean --no-print-directory

re: fclean all

bestre:
	@$(MAKE) bestre -C $(LIB_D) --no-print-directory

tests:	fclean
	@$(MAKE) -C $(TEST_D) --no-print-directory

tests_run:	fclean
	@$(MAKE) run -C $(TEST_D) --no-print-directory

coverage:	fclean
	@$(MAKE) coverage -C $(TEST_D) --no-print-directory

.PHONY:	all	debug	clean	fclean	re	bestre	test	tests_run	coverage
