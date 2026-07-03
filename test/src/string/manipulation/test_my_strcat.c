/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_strcat
*/

#include "test.h"

Test(my_strcat, null_entry)
{
    cr_assert_null(my_strcat(NULL, "World"));
    cr_assert_null(my_strcat("Hello", NULL));
}

Test(my_strcat, concat)
{
    char dest[20] = "Hello ";
    char dest2[10] = "";

    cr_assert_str_eq(my_strcat(dest, "World"), "Hello World");
    cr_assert_str_eq(my_strcat(dest, ""), "Hello World");
    cr_assert_str_eq(my_strcat(dest2, "Hi"), "Hi");
}

Test(my_strncat, null_entry)
{
    cr_assert_null(my_strncat(NULL, "World", 1));
    cr_assert_null(my_strncat("Hello ", NULL, 1));
    cr_assert_null(my_strncat("Hello ", "World", -1));
}

Test(my_strncat, concat)
{
    char dest[20] = "Hello ";
    char dest2[10] = "";

    cr_assert_str_eq(my_strncat(dest, "World", 6), "Hello World");
    cr_assert_str_eq(my_strncat(dest, "", 0), "Hello World");
    cr_assert_str_eq(my_strncat(dest2, "Hi", 2), "Hi");
}
