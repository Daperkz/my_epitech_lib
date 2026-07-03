/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_showstr
*/

#include "test.h"

Test(my_showstr, null_parameters, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_showstr(NULL), 0);
    cr_assert_stdout_eq_str("");
}

Test(my_showstr, only_printable, .init = cr_redirect_stdout)
{
    char *str = "hello";
    cr_assert_eq(my_showstr(str), 5);
    cr_assert_stdout_eq_str("hello");
}

Test(my_showstr, only_nonprintable, .init = cr_redirect_stdout)
{
    char str[] = {27, 127, 4, '\0'};

    cr_assert_eq(my_showstr(str), 9);
    cr_assert_stdout_eq_str("\\1b\\7f\\04");
}

Test(my_showstr, mixed, .init = cr_redirect_stdout)
{
    char str[] = {27, 'A', 127, 4, 'a', '\0'};

    cr_assert_eq(my_showstr(str), 11);
    cr_assert_stdout_eq_str("\\1bA\\7f\\04a");
}
