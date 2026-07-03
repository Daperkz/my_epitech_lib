/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** add
*/

#include "test.h"

Test(ll_append, null_parameters)
{
    int data = 42;

    cr_assert_eq(ll_append(NULL, &data), EXIT_FAILURE);
}

Test(ll_append, insert_head_node_succeeds)
{
    ll_t *list = ll_create();
    int data = 42;

    cr_assert_not_null(list);
    cr_assert_eq(ll_append(list, &data), EXIT_SUCCESS);
    cr_assert_eq(list->len, 1);
    cr_assert_not_null(list->head);
    cr_assert_eq(*(int *)list->head->data, data);
    cr_assert_null(list->head->next);
    ll_destroy(list, NULL);
}

Test(ll_append, insert_multiple_node_succeeds)
{
    ll_t *list = ll_create();
    int x = 42;
    int y = 24;
    int z = 24;

    cr_assert_not_null(list);
    cr_assert_eq(ll_append(list, &x), EXIT_SUCCESS);
    cr_assert_eq(ll_append(list, &y), EXIT_SUCCESS);
    cr_assert_eq(ll_append(list, &z), EXIT_SUCCESS);
    cr_assert_eq(list->len, 3);
    cr_assert_not_null(list->head);
    cr_assert_eq(*(int *)list->head->data, x);
    cr_assert_eq(*(int *)list->head->next->data, y);
    cr_assert_eq(*(int *)list->head->next->next->data, z);
    ll_destroy(list, NULL);
}

Test(ll_append, malloc_fail, .fini = reset_malloc_wrapper)
{
    ll_t *list = ll_create();
    int x = 42;

    cr_assert_not_null(list);
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_eq(ll_append(list, &x), EXIT_FAILURE);
    ll_destroy(list, NULL);
}

Test(ll_insert, null_parameters)
{
    int data = 42;

    cr_assert_eq(ll_insert(NULL, &data), EXIT_FAILURE);
}

Test(ll_insert, insert_head_node_succeeds)
{
    ll_t *list = ll_create();
    int data = 42;

    cr_assert_not_null(list);
    cr_assert_eq(ll_insert(list, &data), EXIT_SUCCESS);
    cr_assert_eq(list->len, 1);
    cr_assert_not_null(list->head);
    cr_assert_eq(*(int *)list->head->data, data);
    cr_assert_null(list->head->next);
    ll_destroy(list, NULL);
}

Test(ll_insert, insert_two_node_succeeds)
{
    ll_t *list = ll_create();
    int x = 42;
    int y = 24;

    cr_assert_not_null(list);
    cr_assert_eq(ll_insert(list, &x), EXIT_SUCCESS);
    cr_assert_eq(ll_insert(list, &y), EXIT_SUCCESS);
    cr_assert_eq(list->len, 2);
    cr_assert_not_null(list->head);
    ll_destroy(list, NULL);
}

Test(ll_insert, malloc_fail, .fini = reset_malloc_wrapper)
{
    ll_t *list = ll_create();
    int x = 42;

    cr_assert_not_null(list);
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_eq(ll_insert(list, &x), EXIT_FAILURE);
    ll_destroy(list, NULL);
}
