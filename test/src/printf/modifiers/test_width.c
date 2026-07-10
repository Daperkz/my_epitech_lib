/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_width
*/

#include "test.h"

Test(apply_width, no_padding_needed)
{
    pf_info_t info = {.width = 3, .left = 0, .zero = 0};
    char *str = strdup("12345");
    char *res;

    cr_assert_not_null(str);
    res = apply_width(str, &info);
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "12345");
    free(res);
}

Test(apply_width, right_alignment_spaces)
{
    pf_info_t info = {.width = 5, .left = 0, .zero = 0};
    char *str = strdup("42");
    char *res;

    cr_assert_not_null(str);
    res = apply_width(str, &info);
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "   42");
    free(res);
}

Test(apply_width, left_alignment_spaces)
{
    pf_info_t info = {.width = 5, .left = 1, .zero = 0};
    char *str = strdup("42");
    char *res;

    cr_assert_not_null(str);
    res = apply_width(str, &info);
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "42   ");
    free(res);
}

Test(apply_width, right_alignment_zeros_positive)
{
    pf_info_t info = {.width = 5, .left = 0, .zero = 1};
    char *str = strdup("42");
    char *res;

    cr_assert_not_null(str);
    res = apply_width(str, &info);
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "00042");
    free(res);
}

Test(apply_width, right_alignment_zeros_negative)
{
    pf_info_t info = {.width = 6, .left = 0, .zero = 1};
    char *str = strdup("-42");
    char *res;

    cr_assert_not_null(str);
    res = apply_width(str, &info);
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "-00042");
    free(res);
}

Test(apply_width, right_alignment_spaces_negative)
{
    pf_info_t info = {.width = 6, .left = 0, .zero = 0};
    char *str = strdup("-42");
    char *res;

    cr_assert_not_null(str);
    res = apply_width(str, &info);
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "   -42");
    free(res);
}

Test(apply_width, left_alignment_zeros_ignored)
{
    pf_info_t info = {.width = 5, .left = 1, .zero = 1};
    char *str = strdup("42");
    char *res;

    cr_assert_not_null(str);
    res = apply_width(str, &info);
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "42   ");
    free(res);
}

Test(apply_width, left_alignment_zeros_ignored_negative)
{
    pf_info_t info = {.width = 6, .left = 1, .zero = 1};
    char *str = strdup("-42");
    char *res;

    cr_assert_not_null(str);
    res = apply_width(str, &info);
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "-42   ");
    free(res);
}

Test(apply_width, malloc_failure, .fini = reset_malloc_wrapper)
{
    pf_info_t info = {.width = 5, .left = 0, .zero = 0};
    char *str = strdup("42");
    char *res;

    cr_assert_not_null(str);
    set_malloc_fail(1);
    set_malloc_count(0);
    res = apply_width(str, &info);
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "42");
    free(res);
}
