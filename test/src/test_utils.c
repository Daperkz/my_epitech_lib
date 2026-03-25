/*
** EPITECH PROJECT, 2026
** test_utils.c
** File description:
** test_utils
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>

#include "my/utils.h"

Test(my_swap, swap_integers)
{
    int a = 42;
    int b = 21;
    my_swap(&a, &b);
    cr_assert_eq(a, 21);
    cr_assert_eq(b, 42);
}

Test(my_sort_int_array, sort_basic)
{
    int tab[] = {5, 2, 8, 1, 9};
    my_sort_int_array(tab, 5);
    cr_assert_eq(tab[0], 1);
    cr_assert_eq(tab[4], 9);
}

Test(my_sort_int_array, sort_empty)
{
    int *tab = NULL;
    my_sort_int_array(tab, 0);
    cr_assert_eq(tab, NULL);
}

Test(concat_params, basic_concat)
{
    char *argv[] = {"./test", "hello", "world"};
    char *res = concat_params(3, argv);
    cr_assert_str_eq(res, "./test\nhello\nworld");
    free(res);
}

Test(my_itoab, signed_integer)
{
    char *res = my_itoab(-42, BASE10);
    cr_assert_str_eq(res, "-42");
    free(res);
}

Test(my_itoab, int_min_check)
{
    char *res = my_itoab(-2147483648, BASE10);
    cr_assert_str_eq(res, "-2147483648");
    free(res);
}

Test(my_uitoab, unsigned_check)
{
    char *res = my_uitoab(4294967295, BASE10);
    cr_assert_str_eq(res, "4294967295");
    free(res);
}

Test(my_ltoab, long_check)
{
    char *res = my_ltoab(123456789012345, BASE10);
    cr_assert_str_eq(res, "123456789012345");
    free(res);
}

Test(my_ftoa, float_basic)
{
    char *res = my_ftoa(3.1415, 2);
    cr_assert_str_eq(res, "3.14");
    free(res);
}

Test(my_ftoa, float_negative)
{
    char *res = my_ftoa(-0.5, 1);
    cr_assert_str_eq(res, "-0.5");
    free(res);
}

Test(my_ftoa, zero_precision)
{
    char *res = my_ftoa(10.9, 0);
    cr_assert_str_eq(res, "11.0");
    free(res);
}
