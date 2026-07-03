/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_strsep
*/

#include "test.h"

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
