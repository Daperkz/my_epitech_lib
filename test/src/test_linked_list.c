/*
** EPITECH PROJECT, 2026
** test_linked_list.c
** File description:
** test_linked_list
*/

#include <criterion/criterion.h>
#include <string.h>
#include <stdlib.h>

#include "my/linked_lists.h"

static int cmp_int(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

static void free_int(void *data)
{
    free(data);
}

Test(ll_t, basic_flow)
{
    ll_t *list = ll_create();
    int *val = malloc(sizeof(int));
    int *found = NULL;
    int *popped = NULL;

    *val = 42;
    cr_assert_not_null(list);
    ll_insert(list, val);
    cr_assert_eq(list->len, 1);
    found = ll_get(list, val, cmp_int);
    cr_assert_eq(*found, 42);
    popped = ll_pop_head(list);
    cr_assert_eq(*popped, 42);
    cr_assert_eq(list->len, 0);
    free(popped);
    ll_destroy(list, free_int);
}

Test(dll_t, tail_operations)
{
    dll_t *list = dll_create();
    int a = 1;
    int b = 2;
    void *data = NULL;

    dll_append(list, &a);
    dll_append(list, &b);
    cr_assert_eq(list->len, 2);
    cr_assert_eq(*(int *)list->tail->data, 2);
    data = dll_pop_tail(list);
    cr_assert_eq(*(int *)data, 2);
    cr_assert_eq(list->len, 1);
    dll_destroy(list, NULL);
}

Test(stack_t, lifo_logic)
{
    stack_t *s = STACK_CREATE();
    int v1 = 10;
    int v2 = 20;

    STACK_PUSH(s, &v1);
    STACK_PUSH(s, &v2);
    cr_assert_eq(*(int *)STACK_POP(s), 20);
    cr_assert_eq(*(int *)STACK_POP(s), 10);
    cr_assert(STACK_IS_EMPTY(s));
    STACK_DESTROY(s, NULL);
}

Test(queue_t, fifo_logic)
{
    queue_t *q = QUEUE_CREATE();
    int v1 = 10;
    int v2 = 20;

    QUEUE_ENQUEUE(q, &v1);
    QUEUE_ENQUEUE(q, &v2);
    cr_assert_eq(*(int *)QUEUE_DEQUEUE(q), 10);
    cr_assert_eq(q->len, 1);
    QUEUE_DESTROY(q, NULL);
}
