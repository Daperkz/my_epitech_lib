/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** add
*/

#include "test.h"

Test(dll_append, null_parameters)
{
    int data = 42;

    cr_assert_eq(dll_append(NULL, &data), EXIT_FAILURE);
}

Test(dll_append, insert_head_node_succeeds)
{
    dll_t *list = dll_create();
    int data = 42;

    cr_assert_not_null(list);
    cr_assert_eq(dll_append(list, &data), EXIT_SUCCESS);
    cr_assert_eq(list->len, 1);
    cr_assert_not_null(list->head);
    cr_assert_not_null(list->tail);
    cr_assert_eq(*(int *)list->head->data, data);
    cr_assert_eq(*(int *)list->tail->data, data);
    cr_assert_null(list->head->prev);
    cr_assert_null(list->head->next);
    dll_destroy(list, NULL);
}

Test(dll_append, insert_two_node_succeeds)
{
    dll_t *list = dll_create();
    int x = 42;
    int y = 24;

    cr_assert_not_null(list);
    cr_assert_eq(dll_append(list, &x), EXIT_SUCCESS);
    cr_assert_eq(dll_append(list, &y), EXIT_SUCCESS);
    cr_assert_eq(list->len, 2);
    cr_assert_not_null(list->head);
    cr_assert_not_null(list->tail);
    cr_assert_eq(*(int *)list->head->data, x);
    cr_assert_eq(*(int *)list->tail->data, y);
    cr_assert_null(list->head->prev);
    cr_assert_eq(list->head->next, list->tail);
    cr_assert_null(list->tail->next);
    cr_assert_eq(list->tail->prev, list->head);
    dll_destroy(list, NULL);
}

Test(dll_append, malloc_fail, .fini = reset_malloc_wrapper)
{
    dll_t *list = dll_create();
    int x = 42;

    cr_assert_not_null(list);
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_eq(dll_append(list, &x), EXIT_FAILURE);
    dll_destroy(list, NULL);
}

Test(dll_insert, null_parameters)
{
    int data = 42;

    cr_assert_eq(dll_insert(NULL, &data), EXIT_FAILURE);
}

Test(dll_insert, insert_head_node_succeeds)
{
    dll_t *list = dll_create();
    int data = 42;

    cr_assert_not_null(list);
    cr_assert_eq(dll_insert(list, &data), EXIT_SUCCESS);
    cr_assert_eq(list->len, 1);
    cr_assert_not_null(list->head);
    cr_assert_not_null(list->tail);
    cr_assert_eq(*(int *)list->head->data, data);
    cr_assert_eq(*(int *)list->tail->data, data);
    cr_assert_null(list->head->prev);
    cr_assert_null(list->head->next);
    dll_destroy(list, NULL);
}

Test(dll_insert, insert_two_node_succeeds)
{
    dll_t *list = dll_create();
    int x = 42;
    int y = 24;

    cr_assert_not_null(list);
    cr_assert_eq(dll_insert(list, &x), EXIT_SUCCESS);
    cr_assert_eq(dll_insert(list, &y), EXIT_SUCCESS);
    cr_assert_eq(list->len, 2);
    cr_assert_not_null(list->head);
    cr_assert_not_null(list->tail);
    cr_assert_eq(*(int *)list->head->data, y);
    cr_assert_eq(*(int *)list->tail->data, x);
    cr_assert_null(list->head->prev);
    cr_assert_eq(list->head->next, list->tail);
    cr_assert_null(list->tail->next);
    cr_assert_eq(list->tail->prev, list->head);
    dll_destroy(list, NULL);
}

Test(dll_insert, malloc_fail, .fini = reset_malloc_wrapper)
{
    dll_t *list = dll_create();
    int x = 42;

    cr_assert_not_null(list);
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_eq(dll_insert(list, &x), EXIT_FAILURE);
    dll_destroy(list, NULL);
}
