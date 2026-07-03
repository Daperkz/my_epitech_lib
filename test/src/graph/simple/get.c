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

Test(ll_get, null_parameters)
{
    ll_t list = {0};
    int data = 1;

    cr_assert_null(ll_get(NULL, &data, compare_ints));
    cr_assert_null(ll_get(&list, &data, NULL));
}

Test(ll_get, basic)
{
    ll_t *list = ll_create();
    int x = 42;
    int y = 24;

    cr_assert_not_null(list);
    cr_assert_eq(ll_insert(list, &x), EXIT_SUCCESS);
    cr_assert_eq(ll_insert(list, &y), EXIT_SUCCESS);
    cr_assert_eq(*(int *)ll_get(list, &x, compare_ints), x);
    ll_destroy(list, NULL);
}

Test(ll_get, no_nodes)
{
    ll_t *list = ll_create();
    int x = 1;

    cr_assert_not_null(list);
    cr_assert_null(ll_get(list, &x, compare_ints));
    ll_destroy(list, NULL);
}
