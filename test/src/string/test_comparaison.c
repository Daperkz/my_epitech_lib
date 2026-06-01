/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_comparaison
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

Test(my_str_islower, all_cases)
{
    cr_assert_eq(my_str_islower(NULL), 0);
    cr_assert_eq(my_str_islower("helloworld"), 1);
    cr_assert_eq(my_str_islower("ABC"), 0);
    cr_assert_eq(my_str_islower("123"), 0);
    cr_assert_eq(my_str_islower("abc{}"), 0);
    cr_assert_eq(my_str_islower(""), 1);
}

Test(my_str_isnum, all_cases)
{
    cr_assert_eq(my_str_isnum(NULL), 0);
    cr_assert_eq(my_str_isnum("123456"), 1);
    cr_assert_eq(my_str_isnum("123a45"), 0);
    cr_assert_eq(my_str_isnum("-123"), 0);
    cr_assert_eq(my_str_isnum(""), 1);
}

Test(my_str_isupper, all_cases)
{
    cr_assert_eq(my_str_isupper(NULL), 0);
    cr_assert_eq(my_str_isupper("HELLOWORLD"), 1);
    cr_assert_eq(my_str_isupper("abc"), 0);
    cr_assert_eq(my_str_isupper("123"), 0);
    cr_assert_eq(my_str_isupper("ABC{}"), 0);
    cr_assert_eq(my_str_isupper(""), 1);
}

Test(my_str_isprintable, all_cases)
{
    char const not_printable[] = {32, 19, 'a', '\0'};

    cr_assert_eq(my_str_isprintable(NULL), 0);
    cr_assert_eq(my_str_isprintable(not_printable), 0);
    cr_assert_eq(my_str_isprintable("Hello World{!}"), 1);
    cr_assert_eq(my_str_isprintable(""), 1);
}
