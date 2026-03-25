/*
** EPITECH PROJECT, 2026
** test_file.c
** File description:
** test_file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "my/file.h"

void create_test_file(const char *name, const char *content)
{
    int fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd != -1) {
        write(fd, content, strlen(content));
        close(fd);
    }
}

void file_cleanup(void)
{
    remove("test_open.txt");
    remove("size_test.txt");
    remove("content_test.txt");
    remove("full_read.txt");
    remove("empty.txt");
}

Test(open_file, existing_file, .fini = file_cleanup)
{
    int fd = open_file("test_open.txt");

    create_test_file("test_open.txt", "data");
    cr_assert(fd != -1);
    close(fd);
}

Test(open_file, missing_file, .fini = file_cleanup)
{
    int fd = open_file("non_existent_file.void");
    cr_assert_eq(fd, -1);
}

Test(get_file_size, check_accuracy, .fini = file_cleanup)
{
    const char *content = "1234567890";
    create_test_file("size_test.txt", content);
    cr_assert_eq(get_file_size("size_test.txt"), 10);
}

Test(get_file_size, empty_file, .fini = file_cleanup)
{
    create_test_file("empty.txt", "");
    cr_assert_eq(get_file_size("empty.txt"), 0);
}

Test(get_file_content, read_from_fd, .fini = file_cleanup)
{
    int fd;
    char *res;

    create_test_file("content_test.txt", "Epitech");
    fd = open("content_test.txt", O_RDONLY);
    res = get_file_content(fd, 7);
    cr_assert_str_eq(res, "Epitech");
    free(res);
    close(fd);
}

Test(read_file, full_path, .fini = file_cleanup)
{
    char *res = read_file("full_read.txt");

    create_test_file("full_read.txt", "Hello World");
    cr_assert_str_eq(res, "Hello World");
    free(res);
}

Test(read_file_dyn, special_files, .fini = file_cleanup)
{
    char *res = read_file_dyn("/proc/self/comm");

    cr_assert_not_null(res);
    cr_assert(strlen(res) > 0);
    free(res);
}
