/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_putchar
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
