/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_strupcase
*/

#include "test.h"

Test(my_strupcase, null_entry)
{
    cr_assert_null(my_strupcase(NULL));
}

Test(my_strupcase, basic)
{
    char src1[] = "HellO WoRLD!{2}";
    char target1[] = "HELLO WORLD!{2}";
    char src2[] = "abc";
    char target2[] = "ABC";

    cr_assert_str_eq(my_strupcase(src1), target1);
    cr_assert_str_eq(my_strupcase(src2), target2);
}
