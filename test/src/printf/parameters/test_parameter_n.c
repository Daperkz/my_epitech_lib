/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_parameter_n
*/

#include "test.h"

Test(parameter_n, basic)
{
    int arg = 10;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper(&coterr, &parameter_n, &arg);
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "");
    cr_assert_eq(arg, 0);
    free(result);
}

Test(parameter_n, printed)
{
    int arg = 10;
    pf_ctx_t coterr = {1, 30, 0};
    char *result;

    result = parameter_wrapper(&coterr, &parameter_n, &arg);
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "");
    cr_assert_eq(arg, 30);
    free(result);
}

Test(parameter_n, malloc_failure, .fini = reset_malloc_wrapper)
{
    int arg = 10;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    set_malloc_fail(1);
    set_malloc_count(0);
    result = parameter_wrapper(&coterr, &parameter_n, &arg);
    cr_assert_null(result);
}

Test(parameter_n, force_stack_branch)
{
    int arg = 10;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper_stack_forced(
        &coterr, &parameter_n, "ptr", &arg
    );
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "");
    free(result);
}
