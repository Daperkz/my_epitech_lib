/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_put_float
*/

#include "test.h"

Test(my_put_float, limits, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_put_float(-2147483647.0, 5), 17);
    cr_assert_stdout_eq_str("-2147483647.00000");
}

Test(my_put_float, divide_1_by_0, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_put_float(1.0 / 0.0, 6), 3);
    cr_assert_stdout_eq_str("inf");
}

Test(my_put_float, divide_neg1_by_0, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_put_float(-1.0 / 0.0, 6), 4);
    cr_assert_stdout_eq_str("-inf");
}

Test(my_put_float, divide_0_by_0, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_put_float(0.0 / 0.0, 6), 3);
    cr_assert_stdout_eq_str("nan");
}

Test(my_put_float, precision_zero, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_put_float(42.75, 0), 2);
    cr_assert_stdout_eq_str("43");
}
