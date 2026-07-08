/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_parameter_x
*/

#include "test.h"

Test(parameter_x, basic)
{
    int arg = 0xa;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper(&coterr, &parameter_x, arg);
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "a");
    free(result);
}

Test(parameter_x, malloc_failure, .fini = reset_malloc_wrapper)
{
    int arg = 0xa;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    set_malloc_fail(1);
    set_malloc_count(0);
    result = parameter_wrapper(&coterr, &parameter_x, arg);
    cr_assert_null(result);
}

Test(parameter_x, force_stack_branch)
{
    int arg = 0x21b1c;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper_stack_forced(
        &coterr, &parameter_x, "int", &arg
    );
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "21b1c");
    free(result);
}

Test(parameter_xx, basic)
{
    int arg = 0xA;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper(&coterr, &parameter_xx, arg);
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "A");
    free(result);
}

Test(parameter_xx, malloc_failure, .fini = reset_malloc_wrapper)
{
    int arg = 0xA;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    set_malloc_fail(1);
    set_malloc_count(0);
    result = parameter_wrapper(&coterr, &parameter_xx, arg);
    cr_assert_null(result);
}

Test(parameter_xx, force_stack_branch)
{
    int arg = 0x21b1c;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper_stack_forced(
        &coterr, &parameter_xx, "int", &arg
    );
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "21B1C");
    free(result);
}
