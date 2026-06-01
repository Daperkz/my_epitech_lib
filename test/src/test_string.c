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
