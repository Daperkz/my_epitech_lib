/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_get_file_size
*/

#include "test.h"

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
