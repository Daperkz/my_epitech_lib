/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_macros
*/

#include "test.h"

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
