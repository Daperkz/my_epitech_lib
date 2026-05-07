/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_array
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>

#include "dkz/string.h"
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

Test(my_str_to_strarr_pairs, fallback_behavior)
{
    char **res1 = my_str_to_strarr_pairs("hello world", " ", NULL);
    char **res2 = my_str_to_strarr_pairs("hello world", " ", "");

    cr_assert_not_null(res1);
    cr_assert_str_eq(res1[0], "hello");
    cr_assert_str_eq(res1[1], "world");
    cr_assert_null(res1[2]);
    cr_assert_not_null(res2);
    cr_assert_str_eq(res2[0], "hello");
    cr_assert_str_eq(res2[1], "world");
    cr_assert_null(res2[2]);
    my_free_strarr(res1);
    my_free_strarr(res2);
}

Test(my_str_to_strarr_pairs, null_safety)
{
    cr_assert_null(my_str_to_strarr_pairs(NULL, " ", "(:)"));
    cr_assert_null(my_str_to_strarr_pairs("hello", NULL, "(:)"));
}

Test(my_str_to_strarr_pairs, standard_stripping)
{
    char **res = my_str_to_strarr_pairs(
        "Hello (World ) -|complex text|-", " \t\n", "(:);-|:|-"
    );

    cr_assert_not_null(res);
    cr_assert_str_eq(res[0], "Hello");
    cr_assert_str_eq(res[1], "World ");
    cr_assert_str_eq(res[2], "complex text");
    cr_assert_null(res[3]);
    my_free_strarr(res);
}

Test(my_str_to_strarr_pairs, adjacent_pairs)
{
    char **res = my_str_to_strarr_pairs("(A)(B)-|C|-", " ", "(:);-|:|-");

    cr_assert_not_null(res);
    cr_assert_str_eq(res[0], "A");
    cr_assert_str_eq(res[1], "B");
    cr_assert_str_eq(res[2], "C");
    cr_assert_null(res[3]);
    my_free_strarr(res);
}

Test(my_str_to_strarr_pairs, separator_only_inside_pair)
{
    char **res = my_str_to_strarr_pairs("word1 (   ) word2", " ", "(:)");

    cr_assert_not_null(res);
    cr_assert_str_eq(res[0], "word1");
    cr_assert_str_eq(res[1], "   ");
    cr_assert_str_eq(res[2], "word2");
    cr_assert_null(res[3]);
    my_free_strarr(res);
}

Test(my_str_to_strarr_pairs, unclosed_pair_at_end)
{
    char **res = my_str_to_strarr_pairs(
        "hello -|unclosed content", " ", "-|:|-"
    );

    cr_assert_null(res);
}

Test(my_str_to_strarr_pairs, empty_pair_content)
{
    char **res = my_str_to_strarr_pairs("hello -- world", " ", "-:-");

    cr_assert_not_null(res);
    cr_assert_str_eq(res[0], "hello");
    cr_assert_str_eq(res[1], "");
    cr_assert_str_eq(res[2], "world");
    cr_assert_null(res[3]);
    my_free_strarr(res);
}

Test(my_str_to_strarr_pairs, overlapping_pair_characters)
{
    char **res = my_str_to_strarr_pairs("<<inside>>", " ", "<:>");

    cr_assert_not_null(res);
    cr_assert_str_eq(res[0], "<inside>");
    cr_assert_null(res[1]);
    my_free_strarr(res);
}

Test(my_len_strarr, basic_length)
{
    char *arr[] = {"one", "two", "three", NULL};
    cr_assert_eq(my_len_strarr(arr), 3);
}

Test(my_len_strarr, null_safety)
{
    char *empty[] = {NULL};

    cr_assert_eq(my_len_strarr(NULL), 0);
    cr_assert_eq(my_len_strarr(empty), 0);
}

Test(my_cpy_strarr, deep_copy_validation)
{
    char *arr[] = {"apple", "banana", NULL};
    char **cpy = my_cpy_strarr(arr);

    cr_assert_not_null(cpy);
    cr_assert_str_eq(cpy[0], "apple");
    cr_assert_str_eq(cpy[1], "banana");
    cr_assert_null(cpy[2]);
    cr_assert_neq(cpy, arr);
    cr_assert_neq(cpy[0], arr[0]);
    my_free_strarr(cpy);
}

Test(my_cpy_strarr, null_input)
{
    cr_assert_null(my_cpy_strarr(NULL));
}

Test(my_put_strarr, standard_output, .init = cr_redirect_stdout)
{
    char *arr[] = {"word1", "word2", "word3", NULL};

    my_put_strarr(arr, '|');
    cr_assert_stdout_eq_str("word1|word2|word3");
}

Test(my_put_strarr, single_element, .init = cr_redirect_stdout)
{
    char *arr[] = {"only", NULL};

    my_put_strarr(arr, ',');
    cr_assert_stdout_eq_str("only");
}

Test(my_put_strarr, null_safety, .init = cr_redirect_stdout)
{
    my_put_strarr(NULL, ' ');
    cr_assert_stdout_eq_str("");
}

Test(my_free_strarr, null_safety)
{
    my_free_strarr(NULL);
}

Test(my_free_strarr, complex_free)
{
    char **res = my_str_to_strarr("testing free logic", " ");

    cr_assert_not_null(res);
    my_free_strarr(res);
}
