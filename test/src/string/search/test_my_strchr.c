/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_strchr
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
