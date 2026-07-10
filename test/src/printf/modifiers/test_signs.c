/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_signs
*/

#include "test.h"

Test(apply_sign_flags, flag_plus_active)
{
    pf_info_t info = {.plus = 1, .space = 0};
    char *str = strdup("42");
    char *res;

    cr_assert_not_null(str);
    res = apply_sign_flags(str, &info, 'd');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "+42");
    free(res);
}

Test(apply_sign_flags, flag_space_active)
{
    pf_info_t info = {.plus = 0, .space = 1};
    char *str = strdup("42");
    char *res;

    cr_assert_not_null(str);
    res = apply_sign_flags(str, &info, 'd');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, " 42");
    free(res);
}

Test(apply_sign_flags, both_flags_active_plus_takes_priority)
{
    pf_info_t info = {.plus = 1, .space = 1};
    char *str = strdup("42");
    char *res;

    cr_assert_not_null(str);
    res = apply_sign_flags(str, &info, 'd');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "+42");
    free(res);
}

Test(apply_sign_flags, already_negative)
{
    pf_info_t info = {.plus = 1, .space = 1};
    char *str = strdup("-42");
    char *res;

    cr_assert_not_null(str);
    res = apply_sign_flags(str, &info, 'd');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "-42");
    free(res);
}

Test(apply_sign_flags, invalid_specifier)
{
    pf_info_t info = {.plus = 1, .space = 1};
    char *str = strdup("42");
    char *res;

    cr_assert_not_null(str);
    res = apply_sign_flags(str, &info, 'x');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "42");
    free(res);
}

Test(apply_sign_flags, no_flags_set)
{
    pf_info_t info = {.plus = 0, .space = 0};
    char *str = strdup("42");
    char *res;

    cr_assert_not_null(str);
    res = apply_sign_flags(str, &info, 'd');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "42");
    free(res);
}

Test(apply_sign_flags, malloc_failure, .fini = reset_malloc_wrapper)
{
    pf_info_t info = {.plus = 1, .space = 0};
    char *str = strdup("42");
    char *res;

    cr_assert_not_null(str);
    set_malloc_fail(1);
    set_malloc_count(0);
    res = apply_sign_flags(str, &info, 'd');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "42");
    free(res);
}
