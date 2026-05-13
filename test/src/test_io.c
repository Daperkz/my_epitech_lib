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
    my_put_float(-2147483647.0, 5);
    cr_assert_stdout_eq_str("-2147483647.00000");
}

Test(my_put_float, negative, .init = cr_redirect_stdout)
{
    my_put_float(-20.0, 5);
    cr_assert_stdout_eq_str("-20.00000");
}

Test(my_put_float, zero_case, .init = cr_redirect_stdout)
{
    my_put_float(0.0, 1);
    cr_assert_stdout_eq_str("0.0");
}

Test(my_put_float, neg_zero_case, .init = cr_redirect_stdout)
{
    my_put_float(-0.0, 1);
    cr_assert_stdout_eq_str("0.0");
}

Test(my_put_float, divide_1_by_0, .init = cr_redirect_stdout)
{
    my_put_float(1.0 / 0.0, 6);
    cr_assert_stdout_eq_str("inf");
}

Test(my_put_float, divide_neg1_by_0, .init = cr_redirect_stdout)
{
    my_put_float(-1.0 / 0.0, 6);
    cr_assert_stdout_eq_str("-inf");
}

Test(my_put_float, divide_0_by_0, .init = cr_redirect_stdout)
{
    my_put_float(0.0 / 0.0, 6);
    cr_assert_stdout_eq_str("nan");
}

Test(my_put_float, precision_zero, .init = cr_redirect_stdout)
{
    my_put_float(42.75, 0);
    cr_assert_stdout_eq_str("43");
}

Test(my_put_float, less_than_zero_value, .init = cr_redirect_stdout)
{
    my_put_float(0.075, 3);
    cr_assert_stdout_eq_str("0.075");
}

Test(my_show_word_array, basic, .init = cr_redirect_stdout)
{
    char *tab[] = {"Hello", "World", NULL};
    my_show_word_array(tab);
    cr_assert_stdout_eq_str("Hello\nWorld\n");
}

Test(my_show_word_array, single_element, .init = cr_redirect_stdout)
{
    char *tab[] = {"OnlyOne", NULL};
    my_show_word_array(tab);
    cr_assert_stdout_eq_str("OnlyOne\n");
}

Test(my_show_word_array, null_element, .init = cr_redirect_stdout)
{
    char **tab = NULL;
    my_show_word_array(tab);
    cr_assert_stdout_eq_str("");
}

Test(my_showstr, non_printable, .init = cr_redirect_stdout)
{
    char str[] = {27, 'a', 0};
    my_showstr(str);
    cr_assert_stdout_eq_str("\\1ba");
}

Test(my_showstr, null_pointer, .init = cr_redirect_stdout)
{
    my_showstr(NULL);
    cr_assert_stdout_eq_str("");
}
