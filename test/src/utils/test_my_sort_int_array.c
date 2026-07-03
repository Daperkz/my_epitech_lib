/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_sort_int_array
*/

#include "test.h"

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
