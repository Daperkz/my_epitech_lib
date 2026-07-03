/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_memmove
*/

#include "test.h"

Test(my_memmove, null_entry)
{
    int arr[10];

    cr_assert_null(my_memmove(NULL, arr, 1));
    cr_assert_null(my_memmove(arr, NULL, 1));
}

Test(my_memmove, basic)
{
    int size = 5;
    int dest[5];
    int src[] = {1, 2, 3, 4, 5};

    my_memmove(dest, src, sizeof(int) * size);
    cr_assert_arr_eq(dest, src, size);
}

Test(my_memmove, overlap_dest_after_src)
{
    int expected[] = {1, 2, 1, 2, 3};
    int arr[] = {1, 2, 3, 4, 5};

    my_memmove(arr + 2, arr, sizeof(int) * 3);
    cr_assert_arr_eq(arr, expected, 5);
}

Test(my_memmove, overlap_dest_before_src)
{
    int expected[] = {3, 4, 5, 4, 5};
    int arr[] = {1, 2, 3, 4, 5};

    my_memmove(arr, arr + 2, sizeof(int) * 3);
    cr_assert_arr_eq(arr, expected, 5);
}
