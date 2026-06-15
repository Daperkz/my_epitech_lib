/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_double_linked_list
*/

#include "test.h"

static int compare_ints(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

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

Test(dll_create, malloc_fail, .fini = reset_malloc_wrapper)
{
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(dll_create());
}

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

Test(dll_dump, no_dump_function_and_list_not_empty, .init = cr_redirect_stdout)
{
    dll_t *list = dll_create();
    char *data = "A";

    cr_assert_eq(dll_insert(list, data), EXIT_SUCCESS);
    dll_dump(list, NULL);
    dll_destroy(list, NULL);
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
