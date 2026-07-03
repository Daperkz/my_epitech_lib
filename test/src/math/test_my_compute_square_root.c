/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** test_my_compute_square_root.c
*/

#include "test.h"

Test(my_compute_square_root, root_logic)
{
    cr_assert_eq(my_compute_square_root(25), 5);
    cr_assert_eq(my_compute_square_root(2), 0);
    cr_assert_eq(my_compute_square_root(1), 1);
    cr_assert_eq(my_compute_square_root(0), 0);
    cr_assert_eq(my_compute_square_root(-25), 0);
}
