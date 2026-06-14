/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_convert
*/

#include "test.h"

Test(my_atoi, conversion)
{
    cr_assert_eq(my_atoi("42"), 42);
    cr_assert_eq(my_atoi("-42"), -42);
    cr_assert_eq(my_atoi("   +123abc45"), 0);
    cr_assert_eq(my_atoi("- 12345"), 0);
    cr_assert_eq(my_atoi("invalid"), 0);
}

Test(my_atoi, stress_test)
{
    cr_assert_eq(my_atoi(NULL), 0);
    cr_assert_eq(my_atoi("--------42"), 42);
    cr_assert_eq(my_atoi("-------42"), -42);
    cr_assert_eq(my_atoi("2147483647"), 2147483647);
    cr_assert_eq(my_atoi("-2147483648"), -2147483648);
    cr_assert_eq(my_atoi(""), 0);
}

Test(my_getnbrspe, conversion)
{
    int error = 0;

    cr_assert_eq(my_getnbrspe("42", &error), 42);
    cr_assert_eq(error, 0);
    error = 0;
    cr_assert_eq(my_getnbrspe("-42", &error), -42);
    cr_assert_eq(error, 0);
    error = 0;
    cr_assert_eq(my_getnbrspe("   +123abc45", &error), 0);
    cr_assert_eq(error, 1);
    error = 0;
    cr_assert_eq(my_getnbrspe("- 12345", &error), 0);
    cr_assert_eq(error, 1);
    error = 0;
    cr_assert_eq(my_getnbrspe("invalid", &error), 0);
    cr_assert_eq(error, 1);
    error = 0;
}

Test(my_getnbrspe, stress_test)
{
    int error = 0;

    cr_assert_eq(my_getnbrspe(NULL, &error), 0);
    cr_assert_eq(error, 1);
    error = 0;
    cr_assert_eq(my_getnbrspe("--------42", &error), 42);
    cr_assert_eq(error, 0);
    error = 0;
    cr_assert_eq(my_getnbrspe("-------42", &error), -42);
    cr_assert_eq(error, 0);
    error = 0;
    cr_assert_eq(my_getnbrspe("2147483647", &error), 2147483647);
    cr_assert_eq(error, 0);
    error = 0;
    cr_assert_eq(my_getnbrspe("-2147483648", &error), -2147483648);
    cr_assert_eq(error, 0);
    error = 0;
    cr_assert_eq(my_getnbrspe("", &error), 0);
    cr_assert_eq(error, 1);
    error = 0;
}

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

Test(my_ftoa, basic_conversion)
{
    char *str1;
    char *str2;
    char *str3;

    str1 = my_ftoa(3.1415, 2);
    cr_assert_not_null(str1);
    cr_assert_str_eq(str1, "3.14");
    free(str1);
    str2 = my_ftoa(-0.5, 1);
    cr_assert_not_null(str2);
    cr_assert_str_eq(str2, "-0.5");
    free(str2);
    str3 = my_ftoa(10.9, 0);
    cr_assert_not_null(str3);
    cr_assert_str_eq(str3, "11");
    free(str3);
}

Test(my_ftoa, edge_cases_and_rounding)
{
    char *str1;
    char *str2;
    char *str3;
    char *str4;

    str1 = my_ftoa(10.99, 1);
    cr_assert_not_null(str1);
    cr_assert_str_eq(str1, "11.0");
    free(str1);
    str2 = my_ftoa(-0.0, 2);
    cr_assert_not_null(str2);
    cr_assert_str_eq(str2, "-0.00");
    free(str2);
    str3 = my_ftoa(1.005, 4);
    cr_assert_not_null(str3);
    cr_assert_str_eq(str3, "1.0050");
    free(str3);
    str4 = my_ftoa(0.0, 2);
    cr_assert_not_null(str4);
    cr_assert_str_eq(str4, "0.00");
    free(str4);
}

Test(my_ftoa, special_cases)
{
    char *str_inf;
    char *str_minf;
    char *str_nan;

    str_inf = my_ftoa(1.0 / 0.0, 2);
    cr_assert_not_null(str_inf);
    cr_assert_str_eq(str_inf, "inf");
    free(str_inf);
    str_minf = my_ftoa(-1.0 / 0.0, 2);
    cr_assert_not_null(str_minf);
    cr_assert_str_eq(str_minf, "-inf");
    free(str_minf);
    str_nan = my_ftoa(0.0 / 0.0, 2);
    cr_assert_not_null(str_nan);
    cr_assert_str_eq(str_nan, "nan");
    free(str_nan);
}

Test(my_ftoa, malloc_fail, .fini = reset_malloc_wrapper)
{
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(my_ftoa(3.1415, 2));
}

Test(my_itoab, signed_integer)
{
    char *res = my_itoab(-42, BASE10);
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "-42");
    free(res);
}

Test(my_itoab, int_min_check)
{
    char *res = my_itoab(-2147483647, BASE10);
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "-2147483647");
    free(res);
}

Test(my_itoab, malloc_fail, .fini = reset_malloc_wrapper)
{
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(my_itoab(-42, BASE10));
}

Test(my_ltoab, basic_conversion)
{
    char *str1;
    char *str2;
    char *str3;
    
    str1 = my_ltoab(123456789012345, BASE10);
    cr_assert_not_null(str1);
    cr_assert_str_eq(str1, "123456789012345");
    free(str1);
    str2 = my_ltoab(-20, BASE10);
    cr_assert_not_null(str2);
    cr_assert_str_eq(str2, "-20");
    free(str2);
    str3 = my_ltoab(0, BASE10);
    cr_assert_not_null(str3);
    cr_assert_str_eq(str3, "0");
    free(str3);
}

Test(my_ltoab, malloc_fail, .fini = reset_malloc_wrapper)
{
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(my_ltoab(-42, BASE10));
}

Test(my_uitoab, basic_conversion)
{
    char *str1;
    char *str2;
    
    str1 = my_uitoab(-1234, BASE10);
    cr_assert_not_null(str1);
    cr_assert_str_eq(str1, "4294966062");
    free(str1);
    str2 = my_uitoab(0, BASE10);
    cr_assert_not_null(str2);
    cr_assert_str_eq(str2, "0");
    free(str2);
}

Test(my_uitoab, malloc_fail, .fini = reset_malloc_wrapper)
{
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(my_uitoab(-42, BASE10));
}
