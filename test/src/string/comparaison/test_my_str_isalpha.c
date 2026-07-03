/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_str_isalpha
*/

#include "test.h"

Test(my_str_isalpha, all_cases)
{
    cr_assert_eq(my_str_isalpha(NULL), 0);
    cr_assert_eq(my_str_isalpha("HelloWorld"), 1);
    cr_assert_eq(my_str_isalpha("Hello World"), 0);
    cr_assert_eq(my_str_isalpha("123"), 0);
    cr_assert_eq(my_str_isalpha("absc"), 1);
    cr_assert_eq(my_str_isalpha("ABC"), 1);
    cr_assert_eq(my_str_isalpha(""), 1);
}
