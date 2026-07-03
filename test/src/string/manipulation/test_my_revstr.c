/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_revstr
*/

#include "test.h"

Test(my_revstr, null_entry)
{
    cr_assert_null(my_revstr(NULL));
}

Test(my_revstr, reverse_odd_sized_string)
{
    char s1[] = "Hello";

    cr_assert_str_eq(my_revstr(s1), "olleH");
}

Test(my_revstr, reverse_even_sized_string)
{
    char str[] = "AB";

    cr_assert_str_eq(my_revstr(str), "BA");
}

Test(my_revstr, special_cases)
{
    char s2[] = "a";
    char s3[] = "";

    cr_assert_str_eq(my_revstr(s2), "a");
    cr_assert_str_eq(my_revstr(s3), "");
}
