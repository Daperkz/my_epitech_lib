/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_strcpy
*/

#include "test.h"

Test(my_strcpy, copy_logic)
{
    char dest[10];

    cr_assert_eq(my_strcpy(dest, "Hello"), dest);
    cr_assert_str_eq(dest, "Hello");
    my_strcpy(dest, "");
    cr_assert_str_eq(dest, "");
}

Test(my_strncpy, copy_logic)
{
    char dest[10] = {0};

    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
    my_strncpy(dest, "Hi", 5);
    cr_assert_str_eq(dest, "Hi");
}
