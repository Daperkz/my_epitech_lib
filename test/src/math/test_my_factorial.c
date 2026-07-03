/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** test_my_factorial
*/

#include "test.h"

Test(my_factorial, basic_factorial)
{
    cr_assert_eq(my_factorial(0), 1);
    cr_assert_eq(my_factorial(1), 1);
    cr_assert_eq(my_factorial(5), 120);
    cr_assert_eq(my_factorial(13), 6227020800);
    cr_assert_eq(my_factorial(-5), 1);
}
