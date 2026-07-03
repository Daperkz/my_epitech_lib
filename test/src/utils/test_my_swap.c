/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_swap
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
