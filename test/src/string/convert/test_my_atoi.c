/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_atoi
*/

#include "test.h"

Test(my_atoi, conversion)
{
    cr_assert_eq(my_atoi("42"), 42);
    cr_assert_eq(my_atoi("-42"), -42);
    cr_assert_eq(my_atoi("   +123abc45"), 0);
    cr_assert_eq(my_atoi("- 12345"), 0);
    cr_assert_eq(my_atoi("invalid"), 0);
}

Test(my_atoi, stress_test)
{
    cr_assert_eq(my_atoi(NULL), 0);
    cr_assert_eq(my_atoi("--------42"), 42);
    cr_assert_eq(my_atoi("-------42"), -42);
    cr_assert_eq(my_atoi("2147483647"), 2147483647);
    cr_assert_eq(my_atoi("-2147483648"), -2147483648);
    cr_assert_eq(my_atoi(""), 0);
}

Test(my_getnbrspe, conversion)
{
    int error = 0;

    cr_assert_eq(my_getnbrspe("42", &error), 42);
    cr_assert_eq(error, 0);
    error = 0;
    cr_assert_eq(my_getnbrspe("-42", &error), -42);
    cr_assert_eq(error, 0);
    error = 0;
    cr_assert_eq(my_getnbrspe("   +123abc45", &error), 0);
    cr_assert_eq(error, 1);
    error = 0;
    cr_assert_eq(my_getnbrspe("- 12345", &error), 0);
    cr_assert_eq(error, 1);
    error = 0;
    cr_assert_eq(my_getnbrspe("invalid", &error), 0);
    cr_assert_eq(error, 1);
    error = 0;
}

Test(my_getnbrspe, stress_test)
{
    int error = 0;

    cr_assert_eq(my_getnbrspe(NULL, &error), 0);
    cr_assert_eq(error, 1);
    error = 0;
    cr_assert_eq(my_getnbrspe("--------42", &error), 42);
    cr_assert_eq(error, 0);
    error = 0;
    cr_assert_eq(my_getnbrspe("-------42", &error), -42);
    cr_assert_eq(error, 0);
    error = 0;
    cr_assert_eq(my_getnbrspe("2147483647", &error), 2147483647);
    cr_assert_eq(error, 0);
    error = 0;
    cr_assert_eq(my_getnbrspe("-2147483648", &error), -2147483648);
    cr_assert_eq(error, 0);
    error = 0;
    cr_assert_eq(my_getnbrspe("", &error), 0);
    cr_assert_eq(error, 1);
    error = 0;
}
