/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_open_file
*/

#include "test.h"

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
