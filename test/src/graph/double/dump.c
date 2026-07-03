/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** dump
*/

#include "test.h"

static void dump_data(void *data)
{
    char *c = (char *)data;

    write(1, c, 1);
}

Test(dll_dump, null_entry)
{
    dll_t *list = {0};

    dll_dump(NULL, &dump_data);
    dll_dump(list, NULL);
}

Test(dll_dump, basic, .init = cr_redirect_stdout)
{
    dll_t *list = dll_create();
    char *data = "A";

    cr_assert_eq(dll_insert(list, data), EXIT_SUCCESS);
    dll_dump(list, &dump_data);
    cr_assert_stdout_eq_str("A");
    dll_destroy(list, NULL);
}

Test(dll_dump, no_dump_function_and_list_not_empty)
{
    dll_t *list = dll_create();
    char *data = "A";

    cr_assert_eq(dll_insert(list, data), EXIT_SUCCESS);
    dll_dump(list, NULL);
    dll_destroy(list, NULL);
}
