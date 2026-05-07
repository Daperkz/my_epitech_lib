##
## EPITECH PROJECT, 2026
## libdkz
## File description:
## Root Makefile
##


ROOT_D		=	./

DOXYFILE	=	Doxyfile

DOXYGEN		=	doxygen

LIB_D		=	$(ROOT_D)dkz/
TEST_D		=	$(ROOT_D)test/
DOC_D		=	$(ROOT_D)html/


all:
	@$(MAKE) -C $(LIB_D) --no-print-directory

debug:
	@$(MAKE) debug -C $(LIB_D) --no-print-directory

docs:
	@$(DOXYGEN) $(DOXYFILE)
	@echo "Documentation generated in the $(DOC_DIR)/ directory."

clean:
	@$(RM) -r $(DOC_D) latex
	@$(MAKE) -C $(LIB_D) clean --no-print-directory
	@$(MAKE) -C $(TEST_D) clean --no-print-directory

fclean:
	@$(RM) -r $(DOC_D)
	@$(MAKE) -C $(LIB_D) fclean --no-print-directory
	@$(MAKE) -C $(TEST_D) fclean --no-print-directory

re: fclean all

bestre:
	@$(MAKE) bestre -C $(LIB_D) --no-print-directory

tests:
	@$(MAKE) -C $(TEST_D) --no-print-directory

tests_run:
	@$(MAKE) run -C $(TEST_D) --no-print-directory

coverage:
	@$(MAKE) coverage -C $(TEST_D) --no-print-directory

.PHONY:	all	debug	docs	clean	fclean	re	bestre	test	tests_run	coverage
