/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_strjoin
*/

#include "test.h"

Test(my_strjoin, null_entry)
{
    cr_assert_null(my_strjoin(NULL, "World"));
    cr_assert_null(my_strjoin("Hello ", NULL));
}

Test(my_strjoin, basic)
{
    char *str = my_strjoin("Hello ", "World");
    char target[] = "Hello World";

    cr_assert_not_null(str);
    cr_assert_str_eq(str, target);
}

Test(my_strjoin, malloc_fail, .fini = reset_malloc_wrapper)
{
    char *str;

    set_malloc_fail(1);
    set_malloc_count(0);
    str = my_strjoin("Hello ", "World");
    cr_assert_null(str);
}
