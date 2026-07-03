/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** test_my_rounds
*/

#include "test.h"

Test(my_ceil, ceiling_logic)
{
    cr_assert_eq(my_ceil(3.1), 4);
    cr_assert_eq(my_ceil(-3.1), -3);
    cr_assert_eq(my_ceil(5.0), 5);
    cr_assert_eq(my_ceil(0.0), 0);
}

Test(my_floor, floor_logic)
{
    cr_assert_eq(my_floor(3.9), 3);
    cr_assert_eq(my_floor(-3.1), -4);
    cr_assert_eq(my_floor(5.0), 5);
    cr_assert_eq(my_floor(-5.0), -5);
}

Test(my_round, nearest_int)
{
    cr_assert_eq(my_round(3.4), 3);
    cr_assert_eq(my_round(3.6), 4);
    cr_assert_eq(my_round(3.5), 4);
    cr_assert_eq(my_round(-3.5), -4);
}

Test(my_trunc, truncation)
{
    cr_assert_eq(my_trunc(3.9), 3);
    cr_assert_eq(my_trunc(-3.9), -3);
    cr_assert_eq(my_trunc(0.5), 0);
}
