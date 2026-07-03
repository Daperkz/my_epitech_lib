/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_len_strarr
*/

#include "test.h"

Test(my_len_strarr, basic_length)
{
    char *arr[] = {"one", "two", "three", NULL};
    cr_assert_eq(my_len_strarr(arr), 3);
}

Test(my_len_strarr, null_safety)
{
    char *empty[] = {NULL};

    cr_assert_eq(my_len_strarr(NULL), 0);
    cr_assert_eq(my_len_strarr(empty), 0);
}
