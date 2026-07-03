/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_read_file
*/

#include "test.h"

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
