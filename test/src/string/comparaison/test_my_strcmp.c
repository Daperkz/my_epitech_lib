/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_strcmp
*/

#include "test.h"

Test(my_strcmp, basic)
{
    cr_assert_eq(my_strcmp("abc", "abc"), 0);
    cr_assert(my_strcmp("abc", "abd") < 0);
    cr_assert(my_strcmp("abc", "abcd") < 0);
    cr_assert(my_strcmp("abd", "abc") > 0);
    cr_assert(my_strcmp("abcd", "abc") > 0);
    cr_assert_eq(my_strcmp("", ""), 0);
}

Test(my_strncmp, limits)
{
    cr_assert_eq(my_strncmp("hello", "hellz", 4), 0);
    cr_assert_neq(my_strncmp("hello", "hellz", 5), 0);
    cr_assert_eq(my_strncmp("abc", "def", 0), 0);
    cr_assert_eq(my_strncmp("", "", 5), 0);
}

Test(my_strncmp, overflow_n)
{
    cr_assert_eq(my_strncmp("abc", "abc", 10), 0);
    cr_assert_neq(my_strncmp("abc", "abd", 10), 0);
    cr_assert_eq(my_strncmp("a", "b", 0), 0);
}
