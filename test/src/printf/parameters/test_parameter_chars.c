/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_parameter_chars
*/

#include "test.h"

Test(parameter_c, basic)
{
    char arg = 'C';
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper(&coterr, &parameter_c, arg);
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "C");
    free(result);
}

Test(parameter_c, malloc_failure, .fini = reset_malloc_wrapper)
{
    char arg = 'C';
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    set_malloc_fail(1);
    set_malloc_count(0);
    result = parameter_wrapper(&coterr, &parameter_c, arg);
    cr_assert_null(result);
}

Test(parameter_c, force_stack_branch)
{
    char arg = 'C';
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper_stack_forced(&coterr, &parameter_c, "int", &arg);
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "C");
    free(result);
}

Test(parameter_s, basic)
{
    char *arg = "HELLO";
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper(&coterr, &parameter_s, arg);
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "HELLO");
    free(result);
}

Test(parameter_s, null_entry)
{
    char *arg = NULL;
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper(&coterr, &parameter_s, arg);
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "(null)");
    free(result);
}

Test(parameter_s, force_stack_branch)
{
    char *arg = "HELLO";
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper_stack_forced(
        &coterr, &parameter_s, "string", arg
    );
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "HELLO");
    free(result);
}

Test(parameter_percent, basic)
{
    char arg = '%';
    pf_ctx_t coterr = {1, 0, 0};
    char *result;

    result = parameter_wrapper(&coterr, &parameter_percent, arg);
    cr_assert_not_null(result);
    cr_assert_str_eq(result, "%");
    free(result);
}
