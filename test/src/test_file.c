/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_file
*/

#include "test.h"

void create_test_file(const char *name, const char *content)
{
    int fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd != -1) {
        write(fd, content, strlen(content));
        close(fd);
    }
}

Test(open_file, existing_file)
{
    int fd;

    create_test_file("test_open.txt", "data");
    fd = open_file("test_open.txt");
    remove("test_open.txt");
    cr_assert_neq(fd, -1);
    close(fd);
}

Test(open_file, missing_file)
{
    int fd = open_file("non_existent_file.void");
    cr_assert_eq(fd, -1);
}

Test(get_file_size, check_accuracy)
{
    const char *content = "1234567890";
    int size;

    create_test_file("size_test.txt", content);
    size = get_file_size("size_test.txt");
    remove("size_test.txt");
    cr_assert_eq(size, 10);
}

Test(get_file_size, empty_file)
{
    int size;
    create_test_file("empty.txt", "");
    size = get_file_size("empty.txt");
    remove("empty.txt");
    cr_assert_eq(size, 0);
}

Test(get_file_size, non_existing_file)
{
    int size = get_file_size("notafile.txt");

    cr_assert_eq(size, -1);
}

Test(get_file_size_dyn, check_accuracy)
{
    const char *content = "1234567890";
    int size;

    create_test_file("size_test.txt", content);
    size = get_file_size_dyn("size_test.txt");
    remove("size_test.txt");
    cr_assert_eq(size, 10);
}

Test(get_file_size_dyn, empty_file)
{
    int size;
    create_test_file("empty.txt", "");
    size = get_file_size_dyn("empty.txt");
    remove("empty.txt");
    cr_assert_eq(size, 0);
}

Test(get_file_size_dyn, non_existing_file)
{
    int size = get_file_size_dyn("notafile.txt");

    cr_assert_eq(size, -1);
}

Test(get_file_size_dyn, read_fail, .fini = reset_read_wrapper)
{
    int size;

    create_test_file("read_fail.txt", "Hey! Welcome.");
    set_read_fail(1);
    set_read_count(0);
    size = get_file_size_dyn("read_fail.txt");
    remove("read_fail.txt");
    cr_assert_eq(size, -1);
}

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

Test(read_file, full_path)
{
    char *res;

    create_test_file("full_read.txt", "Hello World");
    res = read_file("full_read.txt");
    remove("full_read.txt");
    cr_assert_str_eq(res, "Hello World");
    free(res);
}

Test(read_file, stat_fail, .fini = reset_stat_wrapper)
{
    char *res;

    create_test_file("nah.txt", "No");
    set_stat_fail(1);
    set_stat_count(0);
    res = read_file("nah.txt");
    remove("nah.txt");
    cr_assert_null(res);
}

Test(read_file, read_fail, .fini = reset_read_wrapper)
{
    char *res;

    create_test_file("no.txt", "No");
    set_read_fail(1);
    set_read_count(0);
    res = read_file("no.txt");
    remove("no.txt");
    cr_assert_null(res);
}

Test(read_file, malloc_fail, .fini = reset_malloc_wrapper)
{
    char *res;

    create_test_file("stillno.txt", "No");
    set_malloc_fail(1);
    set_malloc_count(0);
    res = read_file("stillno.txt");
    remove("stillno.txt");
    cr_assert_null(res);
}

Test(read_file_dyn, special_files)
{
    char *res = read_file_dyn("/proc/self/comm");
    int len;

    cr_assert_not_null(res);
    len = strlen(res);
    free(res);
    cr_assert(len > 0);
}

Test(read_file_dyn, non_existing_file)
{
    char *res = read_file_dyn("nofile.txt");

    cr_assert_null(res);
}

Test(read_file_dyn, read_fail, .fini = reset_read_wrapper)
{
    char *res;

    create_test_file("dyn_read.txt", "Epitech");
    set_read_fail(1);
    set_read_count(0);
    res = read_file_dyn("dyn_read.txt");
    remove("dyn_read.txt");
    cr_assert_null(res);
}

Test(read_file_dyn, malloc_fail, .fini = reset_malloc_wrapper)
{
    char *res;

    create_test_file("dyn_malloc.txt", "Epitech");
    set_malloc_fail(1);
    set_malloc_count(0);
    res = read_file_dyn("dyn_malloc.txt");
    remove("dyn_malloc.txt");
    cr_assert_null(res);
}
