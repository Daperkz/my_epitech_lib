/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_strlen
*/

#include "test.h"

Test(my_strlen, null_entry)
{
    cr_assert_eq(my_strlen(NULL), 0);
}

Test(my_strlen, basic)
{
    cr_assert_eq(my_strlen("Hello"), 5);
    cr_assert_eq(my_strlen(""), 0);
    cr_assert_eq(my_strlen(" "), 1);
}

Test(my_strlen_d, null_entry)
{
    cr_assert_eq(my_strlen_d(NULL, 'c'), 0);
}

Test(my_strlen_d, basic)
{
    cr_assert_eq(my_strlen_d("Hello", 'l'), 2);
    cr_assert_eq(my_strlen_d("", 'l'), 0);
    cr_assert_eq(my_strlen_d(" ", 'l'), 1);
}
