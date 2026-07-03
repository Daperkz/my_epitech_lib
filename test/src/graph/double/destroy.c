/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** destroy
*/

#include "test.h"

Test(dll_destroy, null_entry)
{
    dll_t *list = dll_create();

    cr_assert_not_null(list);
    dll_destroy(list, NULL);
    dll_destroy(NULL, NULL);
}

Test(dll_destroy, freeable_content)
{
    dll_t *list = dll_create();
    char *str;

    cr_assert_not_null(list);
    str = my_strdup("Hello");
    cr_assert_not_null(str);
    cr_assert_eq(dll_insert(list, str), EXIT_SUCCESS);
    dll_destroy(list, free);
}
