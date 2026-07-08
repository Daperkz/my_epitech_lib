/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_parameter_f
*/

#include "test.h"

Test(parameter_f, basic)
{
    double arg = 0.182;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper(&coterr, &parameter_f, arg);
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "0.182000");
    free(result);
}

Test(parameter_f, malloc_failure, .fini = reset_malloc_wrapper)
{
    double arg = 0.182;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    set_malloc_fail(1);
    set_malloc_count(0);
    result = parameter_wrapper(&coterr, &parameter_f, arg);
    cr_assert_null(result);
}

Test(parameter_f, force_stack_branch)
{
    pf_ctx_t coterr = {1, 0, 0};
    double arg = 0.182;
    char *result;

    result = parameter_wrapper_stack_forced(
        &coterr, &parameter_f, "float", &arg
    );
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "0.182000");
    free(result);
}

Test(parameter_ff, basic)
{
    double arg = 0.182;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper(&coterr, &parameter_ff, arg);
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "0.182000");
    free(result);
}

Test(parameter_ff, malloc_failure, .fini = reset_malloc_wrapper)
{
    double arg = 0.182;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    set_malloc_fail(1);
    set_malloc_count(0);
    result = parameter_wrapper(&coterr, &parameter_ff, arg);
    cr_assert_null(result);
}

Test(parameter_ff, force_stack_branch)
{
    pf_ctx_t coterr = {1, 0, 0};
    double arg = 0.182;
    char *result;

    result = parameter_wrapper_stack_forced(
        &coterr, &parameter_ff, "float", &arg
    );
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "0.182000");
    free(result);
}
