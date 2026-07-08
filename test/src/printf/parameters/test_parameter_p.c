/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_parameter_p
*/

#include "test.h"

Test(parameter_p, basic)
{
    void *arg = (void *)1298;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper(&coterr, &parameter_p, arg);
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "0x512");
    free(result);
}

Test(parameter_p, malloc_failure, .fini = reset_malloc_wrapper)
{
    int arg = 10;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    set_malloc_fail(1);
    set_malloc_count(0);
    result = parameter_wrapper(&coterr, &parameter_p, &arg);
    cr_assert_null(result);
}

Test(parameter_p, force_stack_branch)
{
    void *arg = NULL;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper_stack_forced(
        &coterr, &parameter_p, "ptr", arg
    );
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "(nil)");
    free(result);
}
