/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_search
*/

#include "test.h"

Test(my_strchr, null_entry)
{
    cr_assert_null(my_strchr(NULL, 'p'));
}


Test(my_strchr, find_char)
{
    char *str = "epitech";

    cr_assert_str_eq(my_strchr(str, 'p'), str + 1);
    cr_assert_str_eq(my_strchr(str, 'e'), str);
    cr_assert_null(my_strchr(str, 'z'));
    cr_assert_str_eq(my_strchr(str, '\0'), str + 7);
}

Test(my_strrchr, null_entry)
{
    cr_assert_null(my_strrchr(NULL, 'p'));
}

Test(my_strrchr, find_char)
{
    char *str = "epitech";

    cr_assert_str_eq(my_strrchr(str, 'p'), str + 1);
    cr_assert_str_eq(my_strrchr(str, 'e'), str + 4);
    cr_assert_null(my_strrchr(str, 'z'));
    cr_assert_str_eq(my_strrchr(str, '\0'), str + 7);
}

Test(my_strsep, null_entry)
{
    char *str = "h e l l o";
    char *null = NULL;
    char *sep = "\t\n ";

    cr_assert_null(my_strsep(NULL, NULL));
    cr_assert_null(my_strsep(NULL, sep));
    cr_assert_null(my_strsep(&str, NULL));
    cr_assert_null(my_strsep(&null, sep));
}

Test(my_strsep, basic)
{
    char str_buff[] = "h e l l o";
    char *str = str_buff;
    char const *sep = "\t\n ";
    char *new = my_strsep(&str, sep);

    cr_assert_str_eq(new, "h");
    cr_assert_str_eq(str, "e l l o");
}


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
