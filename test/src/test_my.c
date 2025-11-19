/*
** EPITECH PROJECT, 2025
** test.c
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my.h"

Test(my_putchar, my_putchar_basic_printing, .init = cr_redirect_stdout) {
    my_putchar('c');
    cr_assert_stdout_eq_str("c");
}

Test(my_putchar, my_putchar_basic_printing_return_value) {
    int x = my_putchar('c');

    cr_assert(x == 1, "expected return value of 1");
}

Test(my_isneg, my_isneg_negative_case) {
    cr_assert(my_isneg(-10) == 1);
}

Test(my_isneg, my_isneg_positive_case) {
    cr_assert(my_isneg(10) == 0);
}

Test(my_isneg, my_isneg_zero_case) {
    cr_assert(my_isneg(0) == 0);
}

Test(my_put_nbr, my_put_nbr_basic_positive_value, .init = cr_redirect_stdout) {
    my_put_nbr(102);
    cr_assert_stdout_eq_str("102");
}

Test(my_put_nbr, my_put_nbr_basic_negative_value, .init = cr_redirect_stdout) {
    my_put_nbr(-182);
    cr_assert_stdout_eq_str("-182");
}

Test(my_put_nbr, my_put_nbr_zero, .init = cr_redirect_stdout) {
    my_put_nbr(0);
    cr_assert_stdout_eq_str("0");
}

Test(my_put_nbr, my_put_nbr_negative_zero, .init = cr_redirect_stdout) {
    my_put_nbr(-0);
    cr_assert_stdout_eq_str("0");
}

Test(my_put_nbr, my_put_nbr_int_min, .init = cr_redirect_stdout) {
    int int_min = -2147483647;

    my_put_nbr(int_min);
    cr_assert_stdout_eq_str("-2147483647");
}

Test(my_put_nbr, my_put_nbr_int_max, .init = cr_redirect_stdout) {
    int int_max = 2147483647;

    my_put_nbr(int_max);
    cr_assert_stdout_eq_str("2147483647");
}

Test(my_swap, my_swap_basic) {
    int a = 2;
    int b = -7;

    my_swap(&a, &b);
    cr_assert((a == -7 && b == 2), "expected values a and b to be swapped");
}

Test(my_putstr, my_putstr_basic_printing, .init = cr_redirect_stdout) {
    my_putstr("Hello World!");
    cr_assert_stdout_eq_str("Hello World!");
}

Test(my_putstr, my_putstr_basic_printing_return_value) {
    int x = my_putstr("Hello World!");

    cr_assert(x == 12, "expected the return value to be the amount of chars");
}

Test(my_putstr, my_putstr_null_param, .init = cr_redirect_stdout) {
    my_putstr(NULL);
    cr_assert_stdout_eq_str("");
}

Test(my_putstr, my_putstr_null_param_return_value) {
    int x = my_putstr(NULL);

    cr_assert(x == -1, "expected the return value to be -1 (error)");
}

Test(my_strlen, my_strlen_basic_str) {
    int x = my_strlen("Hello World!");

    cr_assert(x == 12, "expected the len of the str to be 12");
}

Test(my_strlen, my_strlen_null_entry) {
    int x = my_strlen(NULL);

    cr_assert(x == -1, "expected the return value to be -1 (error)");
}
