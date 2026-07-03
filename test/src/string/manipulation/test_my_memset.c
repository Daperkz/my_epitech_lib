/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_memset
*/

#include "test.h"

Test(my_memset, null_entry)
{
    cr_assert_null(my_memset(NULL, 0, 10));
}

Test(my_memset, basic)
{
    int dest[10];
    int target[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    my_memset(dest, 0, 10);
    cr_assert_arr_eq(dest, target, 10);
}
