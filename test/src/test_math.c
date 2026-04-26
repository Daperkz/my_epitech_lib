/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_math
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "dkz/math.h"

Test(my_is_prime, basic_checks)
{
    cr_assert_eq(my_is_prime(2), 0);
    cr_assert_eq(my_is_prime(7), 1);
    cr_assert_eq(my_is_prime(4), 0);
    cr_assert_eq(my_is_prime(1), 0);
    cr_assert_eq(my_is_prime(0), 0);
    cr_assert_eq(my_is_prime(-7), 0);
}

Test(my_find_prime_sup, next_prime)
{
    cr_assert_eq(my_find_prime_sup(8), 11);
    cr_assert_eq(my_find_prime_sup(13), 13);
    cr_assert_eq(my_find_prime_sup(0), 3);
    cr_assert_eq(my_find_prime_sup(-10), 3);
}

Test(my_compute_power_rec, recursion_logic)
{
    cr_assert_eq(my_compute_power_rec(2, 3), 8);
    cr_assert_eq(my_compute_power_rec(5, 0), 1);
    cr_assert_eq(my_compute_power_rec(5, 1), 5);
    cr_assert_eq(my_compute_power_rec(2, -1), 0);
}

Test(my_compute_square_root, root_logic)
{
    cr_assert_eq(my_compute_square_root(25), 5);
    cr_assert_eq(my_compute_square_root(2), 0);
    cr_assert_eq(my_compute_square_root(1), 1);
    cr_assert_eq(my_compute_square_root(0), 0);
    cr_assert_eq(my_compute_square_root(-25), 0);
}

Test(my_factorial, basic_factorial)
{
    cr_assert_eq(my_factorial(0), 1);
    cr_assert_eq(my_factorial(1), 1);
    cr_assert_eq(my_factorial(5), 120);
    cr_assert_eq(my_factorial(13), 6227020800);
    cr_assert_eq(my_factorial(-5), 1);
}

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

Test(macros, math_macros)
{
    cr_assert_eq(ABS(-10), 10);
    cr_assert_eq(ABS(10), 10);
    cr_assert_eq(MIN(10, 20), 10);
    cr_assert_eq(MAX(10, 20), 20);
    cr_assert_eq(SIGN(-5), -1);
    cr_assert_eq(SIGN(0), 0);
    cr_assert_eq(SIGN(5), 1);
}
