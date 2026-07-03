/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_str_isupper
*/

#include "test.h"

Test(my_str_isupper, all_cases)
{
    cr_assert_eq(my_str_isupper(NULL), 0);
    cr_assert_eq(my_str_isupper("HELLOWORLD"), 1);
    cr_assert_eq(my_str_isupper("abc"), 0);
    cr_assert_eq(my_str_isupper("123"), 0);
    cr_assert_eq(my_str_isupper("ABC{}"), 0);
    cr_assert_eq(my_str_isupper(""), 1);
}
