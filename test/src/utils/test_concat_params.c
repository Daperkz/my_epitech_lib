/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_concat_params
*/

#include "test.h"

Test(concat_params, basic_concat)
{
    char *argv[] = {"./test", "hello", "world"};
    char *res = concat_params(3, argv);

    cr_assert_not_null(res);
    cr_assert_str_eq(res, "./test\nhello\nworld");
    free(res);
}

Test(concat_params, malloc_fail, .fini = reset_malloc_wrapper)
{
    char *argv[] = {"./test", "hello", "world"};

    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(concat_params(3, argv));
}
