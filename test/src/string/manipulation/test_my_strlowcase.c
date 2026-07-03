/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_strlowcase
*/

#include "test.h"

Test(my_strlowcase, null_entry)
{
    cr_assert_null(my_strlowcase(NULL));
}

Test(my_strlowcase, basic)
{
    char src1[] = "HelLO WoRLD!{2}";
    char target1[] = "hello world!{2}";
    char src2[] = "ABC";
    char target2[] = "abc";

    cr_assert_str_eq(my_strlowcase(src1), target1);
    cr_assert_str_eq(my_strlowcase(src2), target2);
}
