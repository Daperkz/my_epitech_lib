/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_putstr
*/

#include "test.h"

Test(my_putstr, null_entry, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_putstr(NULL), 0);
    cr_assert_stdout_eq_str("");
}

Test(my_putstr, basic, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_putstr("Hello"), 5);
    cr_assert_stdout_eq_str("Hello");
}

Test(my_putnstr, null_entry, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_putnstr(NULL, 0), -1);
    cr_assert_eq(my_putnstr(NULL, 1), -1);
    cr_assert_stdout_eq_str("");
}

Test(my_putnstr, basic, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_putnstr("Hello", 3), 3);
    cr_assert_stdout_eq_str("Hel");
}

Test(my_putnstr, negative_arg, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_putnstr("NO", -2), -1);
    cr_assert_stdout_eq_str("");
}

Test(my_fputstr, null_entry, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_fputstr(STDOUT_FD, NULL), 0);
    cr_assert_stdout_eq_str("");
}

Test(my_fputstr, basic, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_fputstr(STDOUT_FD, "Hello"), 5);
    cr_assert_stdout_eq_str("Hello");
}

Test(my_fputstr, invalid_fd)
{
    cr_assert_eq(my_fputstr(-1, "Hello"), -1);
}

Test(my_fputnstr, null_entry, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_fputnstr(STDOUT_FD, NULL, 0), -1);
    cr_assert_eq(my_fputnstr(STDOUT_FD, NULL, 1), -1);
    cr_assert_stdout_eq_str("");
}

Test(my_fputnstr, basic, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_fputnstr(STDOUT_FD, "Hello", 3), 3);
    cr_assert_stdout_eq_str("Hel");
}

Test(my_fputnstr, negative_arg, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_fputnstr(STDOUT_FD, "NO", -2), -1);
    cr_assert_stdout_eq_str("");
}

Test(my_fputnstr, invalid_fd)
{
    cr_assert_eq(my_fputnstr(-1, "Hello", 5), -1);
}
