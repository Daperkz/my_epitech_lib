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
	@$(MAKE) -C $(LIB_D) debug --no-print-directory

docs:
	@$(DOXYGEN) $(DOXYFILE)
	@echo "Documentation generated in the $(DOC_D)/ directory."

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
	@$(MAKE) -C $(LIB_D) bestre --no-print-directory

tests:
	@$(MAKE) -C $(TEST_D) --no-print-directory

tests_debug:
	@$(MAKE) -C $(TEST_D) debug --no-print-directory

tests_run:
	@$(MAKE) -C $(TEST_D) run --no-print-directory

tests_memory_run:
	@$(MAKE) -C $(TEST_D) memory_run --no-print-directory

coverage:
	@$(MAKE) -C $(TEST_D) coverage --no-print-directory

memory_coverage:
	@$(MAKE) -C $(TEST_D) memory_coverage --no-print-directory

.PHONY: all debug clean fclean re bestre 			\
		tests tests_debug tests_run tests_memory_run \
		coverage memory_coverage					\
		docs
