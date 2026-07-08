/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_parameter_g
*/

#include "test.h"

Test(parameter_g, ftoa_failure, .fini = reset_malloc_wrapper)
{
    pf_ctx_t coterr = {0};
    char *result;

    set_malloc_fail(1);
    set_malloc_count(0);
    result = parameter_wrapper(&coterr, &parameter_g, 123.456);
    cr_assert_null(result);
}

Test(parameter_g, my_put_scientific_failure, .fini = reset_malloc_wrapper)
{
    pf_ctx_t coterr = {0};
    char *result;

    set_malloc_fail(1);
    set_malloc_count(3);
    result = parameter_wrapper(&coterr, &parameter_g, 123.456);
    cr_assert_null(result);
}

Test(parameter_g, force_stack_branch)
{
    pf_ctx_t coterr = {1, 0, 0};
    double arg = 123.456;
    char *result;

    result = parameter_wrapper_stack_forced(
        &coterr, &parameter_g, "float", &arg
    );
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "123.456");
    free(result);
}

Test(parameter_g, boundary_cases)
{
    pf_ctx_t coterr = {0};
    char *res1 = parameter_wrapper(&coterr, &parameter_g, 0.000001);
    char *res2 = parameter_wrapper(&coterr, &parameter_g, 10000000.0);
    char *res3 = parameter_wrapper(&coterr, &parameter_g, 0.0);

    cr_assert_not_null(res1);
    cr_assert_str_eq(res1, "1.000000e-06");
    free(res1);
    cr_assert_not_null(res2);
    cr_assert_str_eq(res2, "1.000000e+07");
    free(res2);
    cr_assert_not_null(res3);
    cr_assert_str_eq(res3, "0");
    free(res3);
}

Test(parameter_g, negative_decimal_no_trailing_zeros)
{
    double arg = -123.45;
    pf_ctx_t coterr = {0};
    char *res = parameter_wrapper(&coterr, &parameter_g, arg);

    cr_assert_not_null(res);
    cr_assert_str_eq(res, "-123.45");
    free(res);
}

Test(parameter_g, clear_line_30_and_41_true)
{
    double arg = 123456.178912;
    pf_ctx_t coterr = {0};
    char *res = parameter_wrapper(&coterr, &parameter_g, arg);

    cr_assert_not_null(res);
    cr_assert_str_eq(res, "123456.2");
    free(res);
}

Test(parameter_gg, decimal_shorter)
{
    double arg = 123.456;
    pf_ctx_t coterr = {0};
    char *result = parameter_wrapper(&coterr, &parameter_gg, arg);

    cr_assert_not_null(result);
    cr_assert_str_eq(result, "123.456");
    free(result);
}

Test(parameter_gg, scientific_shorter)
{
    double arg = 0.000000123;
    pf_ctx_t coterr = {0};
    char *result = parameter_wrapper(&coterr, &parameter_gg, arg);

    cr_assert_not_null(result);
    cr_assert_str_eq(result, "1.230000E-07");
    free(result);
}

Test(parameter_gg, ftoa_failure, .fini = reset_malloc_wrapper)
{
    pf_ctx_t coterr = {0};
    char *result;

    set_malloc_fail(1);
    set_malloc_count(0);
    result = parameter_wrapper(&coterr, &parameter_gg, 123.456);
    cr_assert_null(result);
}

Test(parameter_gg, my_put_scientific_failure, .fini = reset_malloc_wrapper)
{
    pf_ctx_t coterr = {0};
    char *result;

    set_malloc_fail(1);
    set_malloc_count(3);
    result = parameter_wrapper(&coterr, &parameter_gg, 123.456);
    cr_assert_null(result);
}

Test(parameter_gg, force_stack_branch)
{
    pf_ctx_t coterr = {1, 0, 0};
    double arg = 123.456;
    char *result;

    result = parameter_wrapper_stack_forced(
        &coterr, &parameter_gg, "float", &arg
    );
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "123.456");
    free(result);
}
