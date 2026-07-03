/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_uitoab
*/

#include "test.h"

Test(my_uitoab, basic_conversion)
{
    char *str1;
    char *str2;

    str1 = my_uitoab(-1234, BASE10);
    cr_assert_not_null(str1);
    cr_assert_str_eq(str1, "4294966062");
    free(str1);
    str2 = my_uitoab(0, BASE10);
    cr_assert_not_null(str2);
    cr_assert_str_eq(str2, "0");
    free(str2);
}

Test(my_uitoab, malloc_fail, .fini = reset_malloc_wrapper)
{
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(my_uitoab(-42, BASE10));
}
