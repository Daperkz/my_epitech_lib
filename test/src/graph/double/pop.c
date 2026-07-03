/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** pop
*/

#include "test.h"

static int compare_ints(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

Test(dll_pop_head, null_parameters)
{
    dll_t list = {0};

    cr_assert_null(dll_pop_head(NULL));
    cr_assert_null(dll_pop_head(&list));
}

Test(dll_pop_head, one_element)
{
    dll_t *list = dll_create();
    int x = 42;

    cr_assert_not_null(list);
    cr_assert_eq(dll_insert(list, &x), EXIT_SUCCESS);
    cr_assert_eq(dll_pop_head(list), &x);
    cr_assert_null(list->head);
    cr_assert_null(list->tail);
    dll_destroy(list, NULL);
}

Test(dll_pop_head, two_element)
{
    dll_t *list = dll_create();
    int x = 42;
    int y = 24;

    cr_assert_not_null(list);
    cr_assert_eq(dll_insert(list, &x), EXIT_SUCCESS);
    cr_assert_eq(dll_insert(list, &y), EXIT_SUCCESS);
    cr_assert_eq(dll_pop_head(list), &y);
    cr_assert_not_null(list->head);
    cr_assert_not_null(list->tail);
    cr_assert_null(list->head->prev);
    cr_assert_eq(list->head->data, &x);
    cr_assert_null(list->tail->next);
    cr_assert_eq(list->tail->data, &x);
    dll_destroy(list, NULL);
}

Test(dll_pop_tail, null_parameters)
{
    dll_t list = {0};

    cr_assert_null(dll_pop_tail(NULL));
    cr_assert_null(dll_pop_tail(&list));
}

Test(dll_pop_tail, one_element)
{
    dll_t *list = dll_create();
    int x = 42;

    cr_assert_not_null(list);
    cr_assert_eq(dll_insert(list, &x), EXIT_SUCCESS);
    cr_assert_eq(dll_pop_tail(list), &x);
    cr_assert_null(list->head);
    cr_assert_null(list->tail);
    dll_destroy(list, NULL);
}

Test(dll_pop_tail, two_element)
{
    dll_t *list = dll_create();
    int x = 42;
    int y = 24;

    cr_assert_not_null(list);
    cr_assert_eq(dll_insert(list, &x), EXIT_SUCCESS);
    cr_assert_eq(dll_insert(list, &y), EXIT_SUCCESS);
    cr_assert_eq(dll_pop_tail(list), &x);
    cr_assert_not_null(list->head);
    cr_assert_not_null(list->tail);
    cr_assert_null(list->head->prev);
    cr_assert_eq(list->head->data, &y);
    cr_assert_null(list->tail->next);
    cr_assert_eq(list->tail->data, &y);
    dll_destroy(list, NULL);
}

Test(dll_pop, null_parameters)
{
    dll_t list = {0};
    int data = 42;

    cr_assert_null(dll_pop(NULL, &data, compare_ints));
    cr_assert_null(dll_pop(&list, &data, NULL));
    cr_assert_null(dll_pop(&list, NULL, compare_ints));
}

Test(dll_pop, one_element)
{
    dll_t *list = dll_create();
    int x = 42;

    cr_assert_not_null(list);
    cr_assert_eq(dll_insert(list, &x), EXIT_SUCCESS);
    cr_assert_eq(dll_pop(list, &x, compare_ints), &x);
    cr_assert_null(list->head);
    dll_destroy(list, NULL);
}

Test(dll_pop, remove_middle_element_between_three)
{
    dll_t *list = dll_create();
    int x = 42;
    int y = 0;
    int z = -182;

    cr_assert_not_null(list);
    cr_assert_eq(dll_insert(list, &x), EXIT_SUCCESS);
    cr_assert_eq(dll_insert(list, &y), EXIT_SUCCESS);
    cr_assert_eq(dll_insert(list, &z), EXIT_SUCCESS);
    cr_assert_eq(dll_pop(list, &y, compare_ints), &y);
    cr_assert_eq(list->head->next, list->tail);
    cr_assert_eq(list->tail->prev, list->head);
    cr_assert_eq(list->head->data, &z);
    cr_assert_eq(list->tail->data, &x);
    dll_destroy(list, NULL);
}

Test(dll_pop, cmp_is_null_with_valid_list)
{
    dll_t *list = dll_create();
    int x = 42;

    cr_assert_not_null(list);
    cr_assert_eq(dll_insert(list, &x), EXIT_SUCCESS);
    cr_assert_null(dll_pop(list, &x, NULL));
    dll_destroy(list, NULL);
}

Test(dll_pop, element_not_found_loop_exhaustion)
{
    dll_t *list = dll_create();
    int x = 42;
    int missing = 99;

    cr_assert_not_null(list);
    cr_assert_eq(dll_insert(list, &x), EXIT_SUCCESS);
    cr_assert_null(dll_pop(list, &missing, compare_ints));
    dll_destroy(list, NULL);
}
