/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_utils
*/

#include "test.h"

Test(my_swap, swap_integers)
{
    int a = 42;
    int b = 21;

    my_swap(&a, &b);
    cr_assert_eq(a, 21);
    cr_assert_eq(b, 42);
}

Test(my_sort_int_array, sort_basic)
{
    int tab[] = {5, 2, 8, 1, 9};

    my_sort_int_array(tab, 5);
    cr_assert_eq(tab[0], 1);
    cr_assert_eq(tab[4], 9);
}

Test(my_sort_int_array, sort_empty)
{
    int *tab = NULL;

    my_sort_int_array(tab, 0);
    cr_assert_eq(tab, NULL);
}

Test(concat_params, basic_concat)
{
    char *argv[] = {"./test", "hello", "world"};
    char *res = concat_params(3, argv);

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
