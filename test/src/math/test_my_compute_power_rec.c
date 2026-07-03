/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_compute_power_rec.c
*/

#include "test.h"

Test(my_compute_power_rec, recursion_logic)
{
    cr_assert_eq(my_compute_power_rec(2, 3), 8);
    cr_assert_eq(my_compute_power_rec(5, 0), 1);
    cr_assert_eq(my_compute_power_rec(5, 1), 5);
    cr_assert_eq(my_compute_power_rec(2, -1), 0);
}
