/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_get_file_content
*/

#include "test.h"

Test(get_file_content, read_from_fd)
{
    int fd;
    char *res;

    create_test_file("content_test.txt", "Epitech");
    fd = open("content_test.txt", O_RDONLY);
    res = get_file_content(fd, 7);
    remove("content_test.txt");
    cr_assert_str_eq(res, "Epitech");
    free(res);
    close(fd);
}

Test(get_file_content, read_from_invalid_fd)
{
    int fd = -1;
    char *res;

    res = get_file_content(fd, 7);
    cr_assert_null(res);
}


Test(get_file_content, malloc_fail, .fini = reset_malloc_wrapper)
{
    char *res;

    set_malloc_fail(1);
    set_malloc_count(0);
    res = get_file_content(1, 7);
    cr_assert_null(res);
}

Test(get_file_content, read_fail, .fini = reset_read_wrapper)
{
    char *res;

    set_read_fail(1);
    set_read_count(0);
    res = get_file_content(1, 7);
    cr_assert_null(res);
}
