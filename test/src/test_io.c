/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** test_io
*/

#include "test.h"

static void cleanup_file(char *filename)
{
    if (access(filename, F_OK) == 0) {
        remove(filename);
    }
}

Test(my_putchar, basic, .init = cr_redirect_stdout)
{
    my_putchar('A');
    cr_assert_stdout_eq_str("A");
}

Test(my_putchar_fd, file_writing)
{
    int fd = open("test_fd.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    char c;

    cr_assert(fd != -1);
    my_putchar_fd(fd, 'Z');
    close(fd);
    fd = open("test_fd.txt", O_RDONLY);
    read(fd, &c, 1);
    close(fd);
    cleanup_file("test_fd.txt");
    cr_assert_eq(c, 'Z');
}

Test(my_put_nbr, limits, .init = cr_redirect_stdout)
{
    my_put_nbr(-2147483647);
    cr_assert_stdout_eq_str("-2147483647");
}

Test(my_put_nbr, zero_case, .init = cr_redirect_stdout)
{
    my_put_nbr(0);
    cr_assert_stdout_eq_str("0");
}

Test(my_put_nbr_base, basic_negative_value, .init = cr_redirect_stdout)
{
    my_put_nbr_base(-6, BASE10);
    cr_assert_stdout_eq_str("-6");
}

Test(my_put_nbr_base, hex_base, .init = cr_redirect_stdout)
{
    my_put_nbr_base(255, BASE15CAP);
    cr_assert_stdout_eq_str("FF");
}

Test(my_put_nbr_base, binary_base, .init = cr_redirect_stdout)
{
    my_put_nbr_base(10, BASE2);
    cr_assert_stdout_eq_str("1010");
}

Test(my_put_nbr_base, invalid_base, .init = cr_redirect_stdout)
{
    int ret = my_put_nbr_base(42, "0");
    cr_assert_eq(ret, 0);
}

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

Test(my_show_word_array, null_parameter, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_show_word_array(NULL), 0);
    cr_assert_stdout_eq_str("");
}

Test(my_show_word_array, basic, .init = cr_redirect_stdout)
{
    char *tab[] = {"Hello", "World", NULL};

    cr_assert_eq(my_show_word_array(tab), 12);
    cr_assert_stdout_eq_str("Hello\nWorld\n");
}

Test(my_show_word_array, single_element, .init = cr_redirect_stdout)
{
    char *tab[] = {"OnlyOne", NULL};

    cr_assert_eq(my_show_word_array(tab), 8);
    cr_assert_stdout_eq_str("OnlyOne\n");
}

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
