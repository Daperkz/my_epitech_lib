/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_strtrim
*/

#include "test.h"

Test(my_strtrim, null_entry)
{
    cr_assert_null(my_strtrim(NULL, "la"));
    cr_assert_null(my_strtrim("world", NULL));
}

Test(my_strtrim, basic)
{
    char src[] = "   Hello World !  ka";
    char seps[] = " ka";
    char target[] = "Hello World !";

    cr_assert_str_eq(my_strtrim(src, seps), target);
}
