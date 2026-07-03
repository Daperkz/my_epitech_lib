/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_cpy_strarr
*/

#include "test.h"

Test(my_cpy_strarr, deep_copy_validation)
{
    char *arr[] = {"apple", "banana", NULL};
    char **cpy = my_cpy_strarr(arr);

    cr_assert_not_null(cpy);
    cr_assert_str_eq(cpy[0], "apple");
    cr_assert_str_eq(cpy[1], "banana");
    cr_assert_null(cpy[2]);
    cr_assert_neq(cpy, arr);
    cr_assert_neq(cpy[0], arr[0]);
    my_free_strarr(cpy);
}

Test(my_cpy_strarr, null_input)
{
    cr_assert_null(my_cpy_strarr(NULL));
}

Test(my_cpy_strarr, first_malloc_fail, .fini = reset_malloc_wrapper)
{
    char *arr[] = {"apple", "banana", NULL};

    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(my_cpy_strarr(arr));
}

Test(my_cpy_strarr, second_malloc_fail, .fini = reset_malloc_wrapper)
{
    char *arr[] = {"apple", "banana", NULL};

    set_malloc_fail(1);
    set_malloc_count(1);
    cr_assert_null(my_cpy_strarr(arr));
}
