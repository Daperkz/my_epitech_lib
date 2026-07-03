/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** test_my_is_prime
*/

#include "test.h"

Test(my_is_prime, basic_checks)
{
    cr_assert_eq(my_is_prime(2), 0);
    cr_assert_eq(my_is_prime(7), 1);
    cr_assert_eq(my_is_prime(4), 0);
    cr_assert_eq(my_is_prime(1), 0);
    cr_assert_eq(my_is_prime(0), 0);
    cr_assert_eq(my_is_prime(-7), 0);
}
