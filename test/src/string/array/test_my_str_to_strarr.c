/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_str_to_strarr
*/

#include "test.h"

Test(my_str_to_strarr, null_safety)
{
    cr_assert_null(my_str_to_strarr(NULL, " "));
    cr_assert_null(my_str_to_strarr("hello", NULL));
}

Test(my_str_to_strarr, empty_string)
{
    char **res = my_str_to_strarr("", " ");

    cr_assert_not_null(res);
    cr_assert_null(res[0]);
    my_free_strarr(res);
}

Test(my_str_to_strarr, multiple_separators)
{
    char **res = my_str_to_strarr("...Hello...World...", ".");

    cr_assert_not_null(res);
    cr_assert_str_eq(res[0], "Hello");
    cr_assert_str_eq(res[1], "World");
    cr_assert_null(res[2]);
    my_free_strarr(res);
}

Test(my_str_to_strarr, diverse_separators)
{
    char **res = my_str_to_strarr("Tab\tNewline\nSpace ", " \t\n");

    cr_assert_not_null(res);
    cr_assert_str_eq(res[0], "Tab");
    cr_assert_str_eq(res[1], "Newline");
    cr_assert_str_eq(res[2], "Space");
    cr_assert_null(res[3]);
    my_free_strarr(res);
}

Test(my_str_to_strarr, separator_only)
{
    char **res = my_str_to_strarr(":::::", ":");
    cr_assert_not_null(res);
    cr_assert_null(res[0]);
    my_free_strarr(res);
}

Test(my_str_to_strarr, split_logic)
{
    char **res = my_str_to_strarr("hello:world;test", ":;");

    cr_assert_str_eq(res[0], "hello");
    cr_assert_str_eq(res[1], "world");
    cr_assert_str_eq(res[2], "test");
    cr_assert_null(res[3]);
    my_free_strarr(res);
}

Test(my_str_to_strarr, first_malloc_fail, .fini = reset_malloc_wrapper)
{
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(my_str_to_strarr("hello:world;test", ":;"));
}

Test(my_str_to_strarr, second_malloc_fail, .fini = reset_malloc_wrapper)
{
    set_malloc_fail(1);
    set_malloc_count(1);
    cr_assert_null(my_str_to_strarr("hello:world;test", ":;"));
}
