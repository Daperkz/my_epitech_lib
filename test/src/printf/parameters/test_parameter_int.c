/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_parameter_int
*/

#include "test.h"

Test(parameter_d, basic)
{
    int arg = 10;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper(&coterr, &parameter_d, arg);
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "10");
    free(result);
}

Test(parameter_d, malloc_failure, .fini = reset_malloc_wrapper)
{
    int arg = 10;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    set_malloc_fail(1);
    set_malloc_count(0);
    result = parameter_wrapper(&coterr, &parameter_d, arg);
    cr_assert_null(result);
}

Test(parameter_d, force_stack_branch)
{
    int arg = -10;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper_stack_forced(
        &coterr, &parameter_d, "int", &arg
    );
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "-10");
    free(result);
}

Test(parameter_u, basic)
{
    int arg = 10;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper(&coterr, &parameter_u, arg);
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "10");
    free(result);
}

Test(parameter_u, malloc_failure, .fini = reset_malloc_wrapper)
{
    int arg = 10;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    set_malloc_fail(1);
    set_malloc_count(0);
    result = parameter_wrapper(&coterr, &parameter_u, arg);
    cr_assert_null(result);
}

Test(parameter_u, force_stack_branch)
{
    pf_ctx_t coterr = {1, 0, 0};
    int arg = -10;
    char *result;

    result = parameter_wrapper_stack_forced(
        &coterr, &parameter_u, "int", &arg
    );
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "4294967286");
    free(result);
}
