/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_strappend
*/

#include "test.h"

Test(my_strappend, null_entry)
{
    char *dest = "Won't work";

    cr_assert_null(my_strappend(NULL, "Hello"));
    cr_assert_null(my_strappend(&dest, NULL));
}

Test(my_strappend, basic)
{
    char *dest = malloc(sizeof(char) * 7);
    char src[] = "World!";

    my_strcpy(dest, "Hello ");
    cr_assert_str_eq(my_strappend(&dest, src), "Hello World!");
    free(dest);
}

Test(my_strappend, malloc_fail, .fini = reset_malloc_wrapper)
{
    char *dest = malloc(sizeof(char) * 7);
    char src[] = "World!";

    my_strcpy(dest, "Hello ");
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(my_strappend(&dest, src));
    free(dest);
}
