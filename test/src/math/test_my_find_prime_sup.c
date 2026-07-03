/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** test_my_find_prime_sup
*/

#include "test.h"

Test(my_find_prime_sup, next_prime)
{
    cr_assert_eq(my_find_prime_sup(8), 11);
    cr_assert_eq(my_find_prime_sup(13), 13);
    cr_assert_eq(my_find_prime_sup(0), 3);
    cr_assert_eq(my_find_prime_sup(-10), 3);
}
