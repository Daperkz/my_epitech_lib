/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_str_islower
*/

#include "test.h"

Test(my_str_islower, all_cases)
{
    cr_assert_eq(my_str_islower(NULL), 0);
    cr_assert_eq(my_str_islower("helloworld"), 1);
    cr_assert_eq(my_str_islower("ABC"), 0);
    cr_assert_eq(my_str_islower("123"), 0);
    cr_assert_eq(my_str_islower("abc{}"), 0);
    cr_assert_eq(my_str_islower(""), 1);
}
