/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_parameter_o
*/

#include "test.h"

Test(parameter_o, basic)
{
    int arg = 10;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper(&coterr, &parameter_o, arg);
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "12");
    free(result);
}

Test(parameter_o, malloc_failure, .fini = reset_malloc_wrapper)
{
    int arg = 10;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    set_malloc_fail(1);
    set_malloc_count(0);
    result = parameter_wrapper(&coterr, &parameter_o, &arg);
    cr_assert_null(result);
}

Test(parameter_o, force_stack_branch)
{
    int arg = 5402;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper_stack_forced(
        &coterr, &parameter_o, "int", &arg
    );
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "12432");
    free(result);
}
