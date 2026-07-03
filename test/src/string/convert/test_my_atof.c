/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_atof
*/

#include "test.h"

Test(my_atof, precision)
{
    cr_assert_float_eq(my_atof("0.000001"), 0.000001, 0.0000001);
    cr_assert_float_eq(my_atof("-123.456"), -123.456, 0.001);
    cr_assert_float_eq(my_atof("1e2"), 1.0, 0.1);
}

Test(my_atof, conversion)
{
    cr_assert_float_eq(my_atof("3.14"), 3.14, 0.001);
    cr_assert_float_eq(my_atof("-0.5"), -0.5, 0.001);
    cr_assert_float_eq(my_atof("10"), 10.0, 0.001);
    cr_assert_float_eq(my_atof(".5"), 0.5, 0.001);
}

Test(my_atof, stress_test)
{
    cr_assert_float_eq(my_atof(NULL), 0.0, 0.1);
    cr_assert_float_eq(my_atof("invalid"), 0.0, 0.1);
    cr_assert_float_eq(my_atof(""), 0.0, 0.1);
}

Test(my_getfnbrspe, precision)
{
    int error = 0;

    cr_assert_float_eq(my_getfnbrspe("0.000001", &error), 0.000001, 0.0000001);
    cr_assert_eq(error, 0);
    error = 0;
    cr_assert_float_eq(my_getfnbrspe("-123.456", &error), -123.456, 0.001);
    cr_assert_eq(error, 0);
    error = 0;
    cr_assert_float_eq(my_getfnbrspe("1e2", &error), 1.0, 0.1);
    cr_assert_eq(error, 1);
    error = 0;
}

Test(my_getfnbrspe, conversion)
{
    int error = 0;

    cr_assert_float_eq(my_getfnbrspe("3.14", &error), 3.14, 0.001);
    cr_assert_eq(error, 0);
    error = 0;
    cr_assert_float_eq(my_getfnbrspe("-0.5", &error), -0.5, 0.001);
    cr_assert_eq(error, 0);
    error = 0;
    cr_assert_float_eq(my_getfnbrspe("10", &error), 10.0, 0.001);
    cr_assert_eq(error, 0);
    error = 0;
    cr_assert_float_eq(my_getfnbrspe(".5", &error), 0.5, 0.001);
    cr_assert_eq(error, 1);
    error = 0;
}

Test(my_getfnbrspe, stress_test)
{
    int error = 0;

    cr_assert_float_eq(my_getfnbrspe(NULL, &error), 0.0, 0.1);
    cr_assert_eq(error, 1);
    error = 0;
    cr_assert_float_eq(my_getfnbrspe("invalid", &error), 0.0, 0.1);
    cr_assert_eq(error, 1);
    error = 0;
    cr_assert_float_eq(my_getfnbrspe("", &error), 0.0, 0.1);
    cr_assert_eq(error, 1);
    error = 0;
}
