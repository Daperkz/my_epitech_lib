/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_linked_list
*/

#include "test.h"

static int compare_ints(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

static void dump_data(void *data)
{
    char *c = (char *)data;

    write(1, c, 1);
}

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

Test(ll_create, success)
{
    ll_t *list = ll_create();

    cr_assert_not_null(list);
    ll_destroy(list, NULL);
}

Test(ll_create, malloc_fail, .fini = reset_malloc_wrapper)
{
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(ll_create());
}

Test(ll_destroy, null_parameters)
{
    ll_destroy(NULL, NULL);
}

Test(ll_destroy, basic)
{
    ll_t *list = ll_create();

    cr_assert_not_null(list);
    ll_destroy(list, NULL);
}

Test(ll_dump, null_entry)
{
    ll_t *list = {0};

    ll_dump(NULL, &dump_data);
    ll_dump(list, NULL);
}

Test(ll_dump, basic, .init = cr_redirect_stdout)
{
    ll_t *list = ll_create();
    char *data = "A";

    cr_assert_eq(ll_insert(list, data), EXIT_SUCCESS);
    ll_dump(list, &dump_data);
    cr_assert_stdout_eq_str("A");
    ll_destroy(list, NULL);
}

Test(ll_dump, no_dump_function_and_list_not_empty)
{
    ll_t *list = ll_create();
    char *data = "A";

    cr_assert_eq(ll_insert(list, data), EXIT_SUCCESS);
    ll_dump(list, NULL);
    ll_destroy(list, NULL);
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
