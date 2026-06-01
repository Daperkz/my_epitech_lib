/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** Comprehensive string tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>

#include "dkz/string.h"

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
    cr_assert_null(my_strstr("", "Hello"));
    cr_assert_null(my_strstr("Hello", "z"));
    cr_assert_null(my_strstr(NULL, "Hello"));
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
