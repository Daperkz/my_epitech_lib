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

Test(ll_pop_head, null_parameters)
{
    ll_t list = {0};

    cr_assert_null(ll_pop_head(NULL));
    cr_assert_null(ll_pop_head(&list));
}

Test(ll_pop_head, one_element)
{
    ll_t *list = ll_create();
    int x = 42;

    cr_assert_not_null(list);
    cr_assert_eq(ll_insert(list, &x), EXIT_SUCCESS);
    cr_assert_eq(ll_pop_head(list), &x);
    cr_assert_null(list->head);
    ll_destroy(list, NULL);
}

Test(ll_pop_head, two_element)
{
    ll_t *list = ll_create();
    int x = 42;
    int y = 24;

    cr_assert_not_null(list);
    cr_assert_eq(ll_insert(list, &x), EXIT_SUCCESS);
    cr_assert_eq(ll_insert(list, &y), EXIT_SUCCESS);
    cr_assert_eq(ll_pop_head(list), &y);
    cr_assert_not_null(list->head);
    cr_assert_eq(list->head->data, &x);
    ll_destroy(list, NULL);
}

Test(ll_pop, null_parameters)
{
    ll_t list = {0};
    int data = 42;

    cr_assert_null(ll_pop(NULL, &data, compare_ints));
    cr_assert_null(ll_pop(&list, &data, NULL));
    cr_assert_null(ll_pop(&list, NULL, compare_ints));
}

Test(ll_pop, one_element)
{
    ll_t *list = ll_create();
    int x = 42;

    cr_assert_not_null(list);
    cr_assert_eq(ll_insert(list, &x), EXIT_SUCCESS);
    cr_assert_eq(ll_pop(list, &x, compare_ints), &x);
    cr_assert_null(list->head);
    ll_destroy(list, NULL);
}

Test(ll_pop, remove_middle_element_between_three)
{
    ll_t *list = ll_create();
    int x = 42;
    int y = 0;
    int z = -182;

    cr_assert_not_null(list);
    cr_assert_eq(ll_insert(list, &x), EXIT_SUCCESS);
    cr_assert_eq(ll_insert(list, &y), EXIT_SUCCESS);
    cr_assert_eq(ll_insert(list, &z), EXIT_SUCCESS);
    cr_assert_eq(ll_pop(list, &y, compare_ints), &y);
    cr_assert_eq(list->head->data, &z);
    cr_assert_eq(list->head->next->data, &x);
    ll_destroy(list, NULL);
}

Test(ll_pop, cmp_is_null_with_valid_list)
{
    ll_t *list = ll_create();
    int x = 42;

    cr_assert_not_null(list);
    cr_assert_eq(ll_insert(list, &x), EXIT_SUCCESS);
    cr_assert_null(ll_pop(list, &x, NULL));
    ll_destroy(list, NULL);
}

Test(ll_pop, element_not_found_loop_exhaustion)
{
    ll_t *list = ll_create();
    int x = 42;
    int missing = 99;

    cr_assert_not_null(list);
    cr_assert_eq(ll_insert(list, &x), EXIT_SUCCESS);
    cr_assert_null(ll_pop(list, &missing, compare_ints));
    ll_destroy(list, NULL);
}
