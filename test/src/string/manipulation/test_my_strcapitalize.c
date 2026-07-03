/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_strcapitalize
*/

#include "test.h"

Test(my_strcapitalize, null_entry)
{
    cr_assert_null(my_strcapitalize(NULL));
}

Test(my_strcapitalize, basic)
{
    char src[] = "hello world";
    char target[] = "Hello World";
    cr_assert_str_eq(my_strcapitalize(src), target);
}

Test(my_strcapitalize, uppercase_inword)
{
    char src[] = "helLo worLd";
    char target[] = "Hello World";
    cr_assert_str_eq(my_strcapitalize(src), target);
}
