/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_itoab
*/

#include "test.h"

Test(my_itoab, signed_integer)
{
    char *res = my_itoab(-42, BASE10);
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "-42");
    free(res);
}

Test(my_itoab, int_min_check)
{
    char *res = my_itoab(-2147483647, BASE10);
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "-2147483647");
    free(res);
}

Test(my_itoab, malloc_fail, .fini = reset_malloc_wrapper)
{
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(my_itoab(-42, BASE10));
}
