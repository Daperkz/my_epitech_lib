/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_ltoab
*/

#include "test.h"

Test(my_ltoab, basic_conversion)
{
    char *str1;
    char *str2;
    char *str3;

    str1 = my_ltoab(123456789012345, BASE10);
    cr_assert_not_null(str1);
    cr_assert_str_eq(str1, "123456789012345");
    free(str1);
    str2 = my_ltoab(-20, BASE10);
    cr_assert_not_null(str2);
    cr_assert_str_eq(str2, "-20");
    free(str2);
    str3 = my_ltoab(0, BASE10);
    cr_assert_not_null(str3);
    cr_assert_str_eq(str3, "0");
    free(str3);
}

Test(my_ltoab, malloc_fail, .fini = reset_malloc_wrapper)
{
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(my_ltoab(-42, BASE10));
}
