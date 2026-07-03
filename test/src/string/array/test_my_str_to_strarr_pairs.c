/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_str_to_strarr_pairs
*/

#include "test.h"

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

Test(my_str_to_strarr_pairs, mismatched_closing_tags,
    .fini = reset_malloc_wrapper)
{
    char **res = my_str_to_strarr_pairs("( wrong closing -|", " ", "(:);-|:|-");

    cr_assert_null(res);
}

Test(my_str_to_strarr_pairs, mismatched_interleaved_brackets)
{
    char **res = my_str_to_strarr_pairs("(content]still_inside)", " ", "(:);[:]");

    cr_assert_not_null(res);
    cr_assert_str_eq(res[0], "content]still_inside");
    cr_assert_null(res[1]);
    my_free_strarr(res);
}

Test(my_str_to_strarr_pairs, first_malloc_fail, .fini = reset_malloc_wrapper)
{
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(my_str_to_strarr_pairs(
        "Hello (World ) -|complex text|-", " \t\n", "(:);-|:|-"
    ));
}

Test(my_str_to_strarr_pairs, second_malloc_fail, .fini = reset_malloc_wrapper)
{
    set_malloc_fail(1);
    set_malloc_count(1);
    cr_assert_null(my_str_to_strarr_pairs(
        "Hello (World ) -|complex text|-", " \t\n", "(:);-|:|-"
    ));
}
