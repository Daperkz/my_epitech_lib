/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_memcpy
*/

#include "test.h"

Test(my_memcpy, null_entry)
{
    int arr[10];

    cr_assert_null(my_memcpy(NULL, arr, 1));
    cr_assert_null(my_memcpy(arr, NULL, 1));
}

Test(my_memcpy, basic)
{
    int size = 10;
    int dest[10];
    int src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    my_memcpy(dest, src, sizeof(int) * size);
    cr_assert_arr_eq(dest, src, sizeof(int) * size);
}
