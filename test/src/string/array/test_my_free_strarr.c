/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_free_strarr
*/

#include "test.h"

Test(my_free_strarr, null_safety)
{
    my_free_strarr(NULL);
}

Test(my_free_strarr, complex_free)
{
    char **res = my_str_to_strarr("testing free logic", " ");

    cr_assert_not_null(res);
    my_free_strarr(res);
}
