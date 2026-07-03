/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_str_isnum
*/

#include "test.h"

Test(my_str_isnum, all_cases)
{
    cr_assert_eq(my_str_isnum(NULL), 0);
    cr_assert_eq(my_str_isnum("123456"), 1);
    cr_assert_eq(my_str_isnum("123a45"), 0);
    cr_assert_eq(my_str_isnum("-123"), 0);
    cr_assert_eq(my_str_isnum(""), 1);
}
