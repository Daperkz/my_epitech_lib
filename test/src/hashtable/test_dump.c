/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_dump
*/

#include "test.h"

static void dummy_dump_int(void *data)
{
    int *val = (int *)data;
    my_printf("%d", *val);
}

Test(ht_dump, null_parameters, .init = cr_redirect_stdout)
{
    ht_dump(NULL, NULL);
    cr_assert_stdout_eq_str("");
}

Test(ht_dump, empty_table, .init = cr_redirect_stdout)
{
    int size = 2;
    ht_t *ht = ht_create(hash, size);

    cr_assert_not_null(ht);
    ht_dump(ht, NULL);
    cr_assert_stdout_eq_str("[0]:\n[1]:\n");
    ht_destroy(ht, NULL);
}

Test(ht_dump, with_elements_default_pointer_dump, .init = cr_redirect_stdout)
{
    int size = 1;
    ht_t *ht = ht_create(hash, size);
    int data = 42;
    char expected[64];

    cr_assert_not_null(ht);
    cr_assert_eq(ht_insert(ht, "key1", &data), EXIT_SUCCESS);
    ht_dump(ht, NULL);
    sprintf(expected, "[0]:\n> key1: %p\n", (void *)&data);
    cr_assert_stdout_eq_str(expected);
    ht_destroy(ht, NULL);
}

Test(ht_dump, with_elements_custom_dump, .init = cr_redirect_stdout)
{
    int size = 1;
    ht_t *ht = ht_create(hash, size);
    int data = 42;

    cr_assert_not_null(ht);
    cr_assert_eq(ht_insert(ht, "key1", &data), EXIT_SUCCESS);
    ht_dump(ht, dummy_dump_int);
    cr_assert_stdout_eq_str("[0]:\n> key1: 42\n");
    ht_destroy(ht, NULL);
}
Test(ht_dump, custom_dump_with_null_data, .init = cr_redirect_stdout)
{
    int size = 1;
    ht_t *ht = ht_create(hash, size);
    char expected[64];

    cr_assert_not_null(ht);
    cr_assert_eq(ht_insert(ht, "key1", NULL), EXIT_SUCCESS);
    ht_dump(ht, dummy_dump_int);
    sprintf(expected, "[0]:\n> key1: %p\n", (void *)NULL);
    cr_assert_stdout_eq_str(expected);
    ht_destroy(ht, NULL);
}

Test(ht_dump, wrapper_null_bucket_protection, .init = cr_redirect_stdout)
{
    int size = 1;
    node_t mock_node = { .data = NULL, .next = NULL };
    ll_t mock_list = { .head = &mock_node, .len = 1 };
    ht_t *ht = ht_create(hash, size);

    cr_assert_not_null(ht);
    ht->buckets[0] = &mock_list;
    ht_dump(ht, NULL);
    cr_assert_stdout_eq_str("[0]:\n");
    ht->buckets[0] = NULL;
    ht_destroy(ht, NULL);
}
