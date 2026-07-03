/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_strstr
*/

#include "test.h"

Test(my_strstr, null_entry)
{
    char *str = "The quick brown fox";
    char *pattern = "quick";

    cr_assert_null(my_strstr(NULL, pattern));
    cr_assert_null(my_strstr(str, NULL));
}

Test(my_strstr, find_logic)
{
    char *str = "The quick brown fox";

    cr_assert_str_eq(my_strstr(str, "quick"), "quick brown fox");
    cr_assert_eq(my_strstr(str, "lazy"), NULL);
    cr_assert_str_eq(my_strstr(str, ""), str);
}

Test(my_strstr, edge_cases)
{
    cr_assert_str_eq(my_strstr("Hello", ""), "Hello");
    cr_assert_null(my_strstr("", "Hello"));
    cr_assert_null(my_strstr("Hello", "z"));
    cr_assert_null(my_strstr(NULL, "Hello"));
}

Test(my_strstr, complex_boyer_moore_coverage)
{
    char *str = "ABACABACABA";
    char *str_line71 = "A_B_BA_BA";

    cr_assert_str_eq(my_strstr(str, "ABACABA"), "ABACABACABA");
    cr_assert_str_eq(my_strstr(str_line71, "A_BA"), "A_BA");
}
