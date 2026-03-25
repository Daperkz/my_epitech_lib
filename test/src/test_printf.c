/*
** EPITECH PROJECT, 2026
** test_printf.c
** File description:
** test_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "my/printf.h"

Test(my_printf, basic_strings, .init = cr_redirect_stdout)
{
    my_printf("Hello %s %d %c", "World", 42, '!');
    cr_assert_stdout_eq_str("Hello World 42 !");
}

Test(my_printf, hex_and_ptr, .init = cr_redirect_stdout)
{
    int val = 255;

    my_printf("%x", val);
    cr_assert_stdout_eq_str("ff");
}

Test(my_printf, percent_literal, .init = cr_redirect_stdout)
{
    my_printf("100%%");
    cr_assert_stdout_eq_str("100%");
}

Test(my_fprintf, stderr_check, .init = cr_redirect_stderr)
{
    my_fprintf(STDERR_FD, "Error: %d", 404);
    cr_assert_stderr_eq_str("Error: 404");
}

Test(my_fprintf, file_write)
{
    int fd = open("test_printf.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    my_fprintf(fd, "Entry %d", 1);
    close(fd);
    remove("test_printf.txt");
}

Test(my_sprintf, string_format)
{
    char *res = NULL;

    my_sprintf(&res, "Result: %d", 100);
    cr_assert_str_eq(res, "Result: 100");
    free(res);
}
