/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_parameter_a
*/

#include "test.h"

Test(parameter_a, basic)
{
    double arg = 0.182;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper(&coterr, &parameter_a, arg);
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "0x1.74bc6a7ef9db2p-3");
    free(result);
}

Test(parameter_a, malloc_failure, .fini = reset_malloc_wrapper)
{
    double arg = 0.182;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    set_malloc_fail(1);
    set_malloc_count(0);
    result = parameter_wrapper(&coterr, &parameter_a, arg);
    cr_assert_null(result);
}

Test(parameter_a, force_stack_branch)
{
    pf_ctx_t coterr = {1, 0, 0};
    double arg = 0.182;
    char *result;

    result = parameter_wrapper_stack_forced(
        &coterr, &parameter_a, "float", &arg
    );
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "0x1.74bc6a7ef9db2p-3");
    free(result);
}

Test(parameter_aa, basic)
{
    double arg = 0.182;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper(&coterr, &parameter_aa, arg);
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "0X1.74BC6A7EF9DB2P-3");
    free(result);
}

Test(parameter_aa, malloc_failure, .fini = reset_malloc_wrapper)
{
    double arg = 0.182;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    set_malloc_fail(1);
    set_malloc_count(0);
    result = parameter_wrapper(&coterr, &parameter_aa, arg);
    cr_assert_null(result);
}

Test(parameter_aa, force_stack_branch)
{
    pf_ctx_t coterr = {1, 0, 0};
    double arg = 0.182;
    char *result;

    result = parameter_wrapper_stack_forced(
        &coterr, &parameter_aa, "float", &arg
    );
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "0X1.74BC6A7EF9DB2P-3");
    free(result);
}
