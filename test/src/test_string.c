/*
** EPITECH PROJECT, 2026
** test_strings.c
** File description:
** Comprehensive string tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>

#include "my/string.h"

Test(my_strcmp, basic)
{
    cr_assert_eq(my_strcmp("abc", "abc"), 0);
    cr_assert(my_strcmp("abc", "abd") < 0);
    cr_assert(my_strcmp("abd", "abc") > 0);
    cr_assert(my_strcmp("", "") == 0);
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

Test(my_str_isalpha, types)
{
    cr_assert_eq(my_str_isalpha("HelloWorld"), 1);
    cr_assert_eq(my_str_isalpha("Hello World"), 0);
    cr_assert_eq(my_str_isalpha("123"), 0);
    cr_assert_eq(my_str_isalpha(""), 1);
}

Test(my_str_isnum, types)
{
    cr_assert_eq(my_str_isnum("123456"), 1);
    cr_assert_eq(my_str_isnum("123a45"), 0);
    cr_assert_eq(my_str_isnum("-123"), 0);
    cr_assert_eq(my_str_isnum(""), 1);
}

Test(my_strlen, basic)
{
    cr_assert_eq(my_strlen("Hello"), 5);
    cr_assert_eq(my_strlen(""), 0);
    cr_assert_eq(my_strlen(" "), 1);
    cr_assert_eq(my_strlen(NULL), 0);
}

Test(my_strcpy, copy_logic)
{
    char dest[10];

    cr_assert_eq(my_strcpy(dest, "Hello"), dest);
    cr_assert_str_eq(dest, "Hello");
    my_strcpy(dest, "");
    cr_assert_str_eq(dest, "");
}

Test(my_strncpy, copy_logic)
{
    char dest[10] = {0};

    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
    my_strncpy(dest, "Hi", 5);
    cr_assert_str_eq(dest, "Hi");
}

Test(my_strdup, memory)
{
    char *dup = my_strdup("Unique");

    cr_assert_str_eq(dup, "Unique");
    free(dup);
    cr_assert_eq(my_strdup(NULL), NULL);
}

Test(my_revstr, basic)
{
    char s1[] = "Hello";
    char s2[] = "a";
    char s3[] = "";

    cr_assert_str_eq(my_revstr(s1), "olleH");
    cr_assert_str_eq(my_revstr(s2), "a");
    cr_assert_str_eq(my_revstr(s3), "");
}

Test(my_strcat, concat)
{
    char dest[20] = "Hello";
    char dest2[10] = "";

    cr_assert_str_eq(my_strcat(dest, " World"), "Hello World");
    cr_assert_str_eq(my_strcat(dest, ""), "Hello World");
    cr_assert_str_eq(my_strcat(dest2, "Hi"), "Hi");
}

Test(my_strstr, find_logic)
{
    char *str = "The quick brown fox";

    cr_assert_str_eq(my_strstr(str, "quick"), "quick brown fox");
    cr_assert_eq(my_strstr(str, "lazy"), NULL);
    cr_assert_str_eq(my_strstr(str, ""), str);
}

Test(my_strchr, find_char)
{
    char *str = "Epitech";

    cr_assert_eq(my_strchr(str, 'p'), str + 1);
    cr_assert_eq(my_strchr(str, 'z'), NULL);
    cr_assert_eq(my_strchr(str, '\0'), str + 7);
}
Test(my_strstr, edge_cases)
{
    cr_assert_str_eq(my_strstr("Hello", ""), "Hello");
    cr_assert_str_eq(my_strstr("", "Hello"), NULL);
    cr_assert_str_eq(my_strstr("Hello", "z"), NULL);
    cr_assert_str_eq(my_strstr(NULL, "Hello"), NULL);
}

Test(my_str_to_str_arr, separator_only)
{
    char **res = my_str_to_str_arr(":::::", ":");
    cr_assert(res != NULL);
    cr_assert(res[0] == NULL);
    my_free_str_arr(res);
}

Test(my_str_to_str_arr, split_logic)
{
    char **res = my_str_to_str_arr("hello:world;test", ":;");

    cr_assert_str_eq(res[0], "hello");
    cr_assert_str_eq(res[1], "world");
    cr_assert_str_eq(res[2], "test");
    cr_assert_eq(res[3], NULL);
    my_free_str_arr(res);
}

Test(my_len_str_arr, null_safety)
{
    char *empty[] = {NULL};

    cr_assert_eq(my_len_str_arr(NULL), 0);
    cr_assert_eq(my_len_str_arr(empty), 0);
}

Test(my_len_str_arr, array_logic)
{
    char *arr1[] = {"a", "b", "c", NULL};

    cr_assert_eq(my_len_str_arr(arr1), 3);
}

Test(my_atoi, conversion)
{
    cr_assert_eq(my_atoi("42"), 42);
    cr_assert_eq(my_atoi("-42"), -42);
    cr_assert_eq(my_atoi("   +123abc45"), 0);
    cr_assert_eq(my_atoi("invalid"), 0);
}

Test(my_atoi, stress_test)
{
    cr_assert_eq(my_atoi("   ---+++--42abc"), 0);
    cr_assert_eq(my_atoi("2147483647"), 2147483647);
    cr_assert_eq(my_atoi("-2147483648"), -2147483648);
    cr_assert_eq(my_atoi("nothing"), 0);
}

Test(my_atof, precision)
{
    cr_assert_float_eq(my_atof("0.000001"), 0.000001, 0.0000001);
    cr_assert_float_eq(my_atof("-123.456"), -123.456, 0.001);
    cr_assert_float_eq(my_atof("1e2"), 1.0, 0.1);
}

Test(my_atof, conversion)
{
    cr_assert_float_eq(my_atof("3.14"), 3.14, 0.001);
    cr_assert_float_eq(my_atof("-0.5"), -0.5, 0.001);
    cr_assert_float_eq(my_atof("10"), 10.0, 0.001);
    cr_assert_float_eq(my_atof(".5"), 0.5, 0.001);
}
