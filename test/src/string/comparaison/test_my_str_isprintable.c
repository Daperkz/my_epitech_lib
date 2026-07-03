/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_str_isprintable
*/

#include "test.h"

Test(my_str_isprintable, all_cases)
{
    char const not_printable[] = {32, 19, 'a', '\0'};

    cr_assert_eq(my_str_isprintable(NULL), 0);
    cr_assert_eq(my_str_isprintable(not_printable), 0);
    cr_assert_eq(my_str_isprintable("Hello World{!}"), 1);
    cr_assert_eq(my_str_isprintable(""), 1);
}
