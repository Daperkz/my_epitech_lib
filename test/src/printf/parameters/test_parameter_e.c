/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_parameter_e
*/

#include "test.h"

Test(parameter_e, basic)
{
    double arg = 0.182;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper(&coterr, &parameter_e, arg);
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "1.820000e-01");
    free(result);
}

Test(parameter_e, malloc_failure, .fini = reset_malloc_wrapper)
{
    double arg = 0.182;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    set_malloc_fail(1);
    set_malloc_count(0);
    result = parameter_wrapper(&coterr, &parameter_e, arg);
    cr_assert_null(result);
}

Test(parameter_e, force_stack_branch)
{
    pf_ctx_t coterr = {1, 0, 0};
    double arg = 0.182;
    char *result;

    result = parameter_wrapper_stack_forced(
        &coterr, &parameter_e, "float", &arg
    );
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "1.820000e-01");
    free(result);
}

Test(parameter_ee, basic)
{
    double arg = 0.182;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper(&coterr, &parameter_ee, arg);
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "1.820000E-01");
    free(result);
}

Test(parameter_ee, malloc_failure, .fini = reset_malloc_wrapper)
{
    double arg = 0.182;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    set_malloc_fail(1);
    set_malloc_count(0);
    result = parameter_wrapper(&coterr, &parameter_ee, arg);
    cr_assert_null(result);
}

Test(parameter_ee, force_stack_branch)
{
    pf_ctx_t coterr = {1, 0, 0};
    double arg = 0.182;
    char *result;

    result = parameter_wrapper_stack_forced(
        &coterr, &parameter_ee, "float", &arg
    );
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "1.820000E-01");
    free(result);
}
