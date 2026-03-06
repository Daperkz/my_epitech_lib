/*
** EPITECH PROJECT, 2025
** test_io.c
** File description:
** test_io
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>

#include "my/io.h"

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

Test(my_put_nbr_base, hex_base, .init = cr_redirect_stdout)
{
    my_put_nbr_base(255, "0123456789ABCDEF");
    cr_assert_stdout_eq_str("FF");
}

Test(my_put_nbr_base, binary_base, .init = cr_redirect_stdout)
{
    my_put_nbr_base(10, "01");
    cr_assert_stdout_eq_str("1010");
}

Test(my_put_nbr_base, invalid_base, .init = cr_redirect_stdout)
{
    int ret = my_put_nbr_base(42, "0");
    cr_assert_eq(ret, 0);
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

Test(my_showmem, basic_content_check, .init = cr_redirect_stdout)
{
    char *test_str = "Hello";
    my_showmem(test_str, 5);
    cr_assert_stdout_eq_str("^[0-9a-f]{8}:.*4865 6c6c 6f.*Hello.*");
}

Test(my_showmem, null_handling, .init = cr_redirect_stdout)
{
    my_showmem(NULL, 10);
    cr_assert_stdout_eq_str("");
}
