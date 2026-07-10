/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_sharp
*/

#include "test.h"

Test(apply_sharp_flag, octal_needs_padding)
{
    char *str = strdup("77");
    char *res;

    cr_assert_not_null(str);
    res = apply_sharp_flag(str, 'o');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "077");
    free(res);
}

Test(apply_sharp_flag, octal_already_has_zero)
{
    char *str = strdup("077");
    char *res;

    cr_assert_not_null(str);
    res = apply_sharp_flag(str, 'o');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "077");
    free(res);
}

Test(apply_sharp_flag, hex_lowercase_needs_padding)
{
    char *str = strdup("abf");
    char *res;

    cr_assert_not_null(str);
    res = apply_sharp_flag(str, 'x');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "0xabf");
    free(res);
}

Test(apply_sharp_flag, hex_uppercase_needs_padding)
{
    char *str = strdup("ABF");
    char *res;

    cr_assert_not_null(str);
    res = apply_sharp_flag(str, 'X');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "0XABF");
    free(res);
}

Test(apply_sharp_flag, hex_value_is_zero)
{
    char *str = strdup("0");
    char *res;

    cr_assert_not_null(str);
    res = apply_sharp_flag(str, 'x');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "0");
    free(res);
}

Test(apply_sharp_flag, ignore_other_specifiers)
{
    char *str = strdup("42");
    char *res;

    cr_assert_not_null(str);
    res = apply_sharp_flag(str, 'd');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "42");
    free(res);
}

Test(apply_sharp_flag, octal_malloc_fail, .fini = reset_malloc_wrapper)
{
    char *str = strdup("77");
    char *res;

    cr_assert_not_null(str);
    set_malloc_fail(1);
    set_malloc_count(0);
    res = apply_sharp_flag(str, 'o');
    cr_assert_null(res);
    free(str);
}

Test(apply_sharp_flag, hex_malloc_fail, .fini = reset_malloc_wrapper)
{
    char *str = strdup("ff");
    char *res;

    cr_assert_not_null(str);
    set_malloc_fail(1);
    set_malloc_count(0);
    res = apply_sharp_flag(str, 'x');
    cr_assert_null(res);
    free(str);
}
