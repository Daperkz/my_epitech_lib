/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** get
*/

#include "test.h"

static int compare_ints(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

Test(dll_get, null_parameters)
{
    dll_t list = {0};
    int data = 1;

    cr_assert_null(dll_get(NULL, &data, compare_ints));
    cr_assert_null(dll_get(&list, &data, NULL));
}

Test(dll_get, basic)
{
    dll_t *list = dll_create();
    int x = 42;
    int y = 24;

    cr_assert_not_null(list);
    cr_assert_eq(dll_insert(list, &x), EXIT_SUCCESS);
    cr_assert_eq(dll_insert(list, &y), EXIT_SUCCESS);
    cr_assert_eq(*(int *)dll_get(list, &x, compare_ints), x);
    dll_destroy(list, NULL);
}

Test(dll_get, no_nodes)
{
    dll_t *list = dll_create();
    int x = 1;

    cr_assert_not_null(list);
    cr_assert_null(dll_get(list, &x, compare_ints));
    dll_destroy(list, NULL);
}
