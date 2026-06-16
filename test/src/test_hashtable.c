/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_hashtable
*/

#include "test.h"

static void dummy_dump_int(void *data)
{
    int *val = (int *)data;
    my_printf("%d", *val);
}

Test(bucket_create, null_parameters)
{
    char *key = "num";
    int data = 10;
    ht_buckets_t *bucket;

    cr_assert_null(bucket_create(NULL, &data));
    bucket = bucket_create(key, NULL);
    cr_assert_not_null(bucket);
    bucket_destroy(bucket);
}

Test(bucket_create, basic)
{
    char *key = "num";
    int data = 10;
    ht_buckets_t *bucket = bucket_create(key, &data);

    cr_assert_not_null(bucket);
    cr_assert_neq(key, bucket->key);
    cr_assert_str_eq(key, bucket->key);
    cr_assert_eq(&data, bucket->data);
    bucket_destroy(bucket);
}

Test(bucket_create, malloc_fail, .fini = reset_malloc_wrapper)
{
    char *key = "num";
    int data = 10;

    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(bucket_create(key, &data));
}

Test(bucket_create, key_duplication_fails, .fini = reset_malloc_wrapper)
{
    char *key = "num";
    int data = 10;

    set_malloc_fail(1);
    set_malloc_count(1);
    cr_assert_null(bucket_create(key, &data));
}

Test(bucket_destroy, null_parameters)
{
    char *key = "num";
    int data = 10;
    ht_buckets_t *bucket = bucket_create(key, &data);

    bucket_destroy(NULL);
    free(bucket->key);
    bucket->key = NULL;
    bucket_destroy(bucket);
}

Test(bucket_destroy, basic_destroy)
{
    char *key = "num";
    int data = 10;
    ht_buckets_t *bucket = bucket_create(key, &data);

    bucket_destroy(bucket);
}

Test(ht_create, null_parameters)
{
    cr_assert_null(ht_create(NULL, 10));
    cr_assert_null(ht_create(hash, 0));
}

Test(ht_create, basic)
{
    int size = 10;
    ht_t *ht = ht_create(hash, size);

    cr_assert_not_null(ht);
    cr_assert_eq(size, ht->size);
    cr_assert_eq(hash, ht->hash);
    cr_assert_not_null(ht->buckets);
    for (int i = 0; i < size; i++)
        cr_assert_null(ht->buckets[i]);
    ht_destroy(ht, NULL);
}

Test(ht_create, malloc_fail, .fini = reset_malloc_wrapper)
{
    int size = 10;
    
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(ht_create(hash, size));
}

Test(ht_create, buckets_creation_fail, .fini = reset_malloc_wrapper)
{
    int size = 10;
    
    set_malloc_fail(1);
    set_malloc_count(1);
    cr_assert_null(ht_create(hash, size));
}

Test(ht_destroy, null_parameters)
{
    ht_destroy(NULL, NULL);
}

Test(ht_destroy, basic)
{
    int size = 10;
    ht_t *ht = ht_create(hash, size);

    cr_assert_not_null(ht);
    ht_destroy(ht, NULL);
}

Test(ht_destroy, no_buckets)
{
    int size = 10;
    ht_t *ht = ht_create(hash, size);

    cr_assert_not_null(ht);
    free(ht->buckets);
    ht->buckets = NULL;
    ht_destroy(ht, NULL);
}

Test(ht_destroy, with_elements)
{
    int size = 10;
    ht_t *ht = ht_create(hash, size);
    char *key = "nah";
    int data = 1982;

    cr_assert_not_null(ht);
    cr_assert_eq(ht_insert(ht, key, &data), EXIT_SUCCESS);
    ht_destroy(ht, NULL);
}

Test(ht_destroy, with_freeable_elements)
{
    int size = 10;
    char *key = "nah";
    char *data = NULL;
    ht_t *ht = ht_create(hash, size);

    cr_assert_not_null(ht);
    data = my_strdup("content");
    cr_assert_not_null(data);
    cr_assert_eq(ht_insert(ht, key, data), EXIT_SUCCESS);
    ht_destroy(ht, free);
}

Test(ht_destroy, with_freeable_elements_but_data_null)
{
    int size = 10;
    char *key = "nah";
    char *data = NULL;
    ht_t *ht = ht_create(hash, size);

    cr_assert_not_null(ht);
    cr_assert_eq(ht_insert(ht, key, data), EXIT_SUCCESS);
    ht_destroy(ht, free);
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

Test(ht_get, null_parameters)
{
    ht_t ht = {0};
    char *key = "key";

    cr_assert_null(ht_get(&ht, NULL));
    cr_assert_null(ht_get(NULL, key));
}

Test(ht_get, basic)
{
    int size = 10;
    char *key = "key";
    int data = 42;
    ht_t *ht = ht_create(hash, size);

    cr_assert_not_null(ht);
    cr_assert_eq(ht_insert(ht, key, &data), EXIT_SUCCESS);
    cr_assert_eq(ht_get(ht, key), &data);
    ht_destroy(ht, NULL);
}

Test(ht_get, no_matching_key)
{
    int size = 10;
    char *key = "key";
    ht_t *ht = ht_create(hash, size);

    cr_assert_not_null(ht);
    cr_assert_null(ht_get(ht, key));
    ht_destroy(ht, NULL);
}

Test(ht_get, no_matching_bucket)
{
    int size = 10;
    char *key = "key";
    int data = 42;
    ht_t *ht = ht_create(hash, size);
    int index;

    cr_assert_not_null(ht);
    cr_assert_eq(ht_insert(ht, key, &data), EXIT_SUCCESS);
    index = hash(key, size);
    bucket_destroy(ll_pop_head(ht->buckets[index]));
    cr_assert_null(ht_get(ht, key));
    ht_destroy(ht, NULL);
}

Test(sdbm, null_parameters)
{
    int size = 10;
    char *str = "key";

    cr_assert_eq(sdbm(NULL, size), 0);
    cr_assert_eq(sdbm(str, 0), 0);
    cr_assert_eq(sdbm(str, -10), 0);
}

Test(sdbm, basic)
{
    int size = 10;
    char *str = "key";
    int index = sdbm(str, size);

    cr_assert(index >= 0 && index < size);
}

Test(fnv_1a, null_parameters)
{
    int size = 10;
    char *str = "key";

    cr_assert_eq(fnv_1a(NULL, size), 0);
    cr_assert_eq(fnv_1a(str, 0), 0);
    cr_assert_eq(fnv_1a(str, -10), 0);
}

Test(fnv_1a, basic)
{
    int size = 10;
    char *str = "key";
    int index = fnv_1a(str, size);

    cr_assert(index >= 0 && index < size);
}

Test(djb2, null_parameters)
{
    int size = 10;
    char *str = "key";

    cr_assert_eq(djb2(NULL, size), 0);
    cr_assert_eq(djb2(str, 0), 0);
    cr_assert_eq(djb2(str, -10), 0);
}

Test(djb2, basic)
{
    int size = 10;
    char *str = "key";
    int index = djb2(str, size);

    cr_assert(index >= 0 && index < size);
}

Test(hash, null_parameters)
{
    int size = 10;
    char *str = "key";

    cr_assert_eq(hash(NULL, size), 0);
    cr_assert_eq(hash(str, 0), 0);
    cr_assert_eq(hash(str, -10), 0);
}

Test(hash, basic)
{
    int size = 10;
    char *str = "key";
    int index = hash(str, size);

    cr_assert(index >= 0 && index < size);
}

Test(ht_insert, null_parameters)
{
    int size = 10;
    int data = 42;
    char *key = "key";
    ht_t *ht = ht_create(hash, size);

    cr_assert_eq(ht_insert(ht, NULL, &data), EXIT_FAILURE);
    cr_assert_eq(ht_insert(NULL, key, &data), EXIT_FAILURE);
    cr_assert_eq(ht_insert(ht, key, NULL), EXIT_SUCCESS);
    ht_destroy(ht, NULL);
}

Test(ht_insert, basic)
{
    int size = 10;
    int data = 42;
    char *key = "key";
    ht_t *ht = ht_create(hash, size);

    cr_assert_not_null(ht);
    cr_assert_eq(ht_insert(ht, key, &data), EXIT_SUCCESS);
    ht_destroy(ht, NULL);
}

Test(ht_insert, update_already_existing)
{
    int size = 10;
    int x = 42;
    int y = 24;
    char *key = "key";
    ht_t *ht = ht_create(hash, size);
    int index;
    ht_buckets_t *bucket;

    cr_assert_not_null(ht);
    index = hash(key, size);
    cr_assert_eq(ht_insert(ht, key, &x), EXIT_SUCCESS);
    cr_assert_not_null(ht->buckets[index]);
    bucket = ht->buckets[index]->head->data;
    cr_assert_eq(ht_insert(ht, key, &y), EXIT_SUCCESS);
    cr_assert_eq(bucket, ht->buckets[index]->head->data);
    ht_destroy(ht, NULL);
}

Test(ht_insert, matching_index_but_not_same_key)
{
    int size = 10;
    int x = 42;
    int y = 24;
    char *key = "key";
    char *key2 = "kes";
    ht_t *ht = ht_create(hash, size);

    cr_assert_not_null(ht);
    cr_assert_eq(ht_insert(ht, key, &x), EXIT_SUCCESS);
    cr_assert_eq(ht_insert(ht, key2, &y), EXIT_SUCCESS);
    ht_destroy(ht, NULL);
}

Test(ht_insert, bucket_malloc_fail, .fini = reset_malloc_wrapper)
{
    int size = 10;
    int x = 42;
    char *key = "key";
    ht_t *ht = ht_create(hash, size);

    cr_assert_not_null(ht);
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_eq(ht_insert(ht, key, &x), EXIT_FAILURE);
    ht_destroy(ht, NULL);
}

Test(ht_insert, list_malloc_fail, .fini = reset_malloc_wrapper)
{
    int size = 10;
    int x = 42;
    char *key = "key";
    ht_t *ht = ht_create(hash, size);

    cr_assert_not_null(ht);
    set_malloc_fail(1);
    set_malloc_count(2);
    cr_assert_eq(ht_insert(ht, key, &x), EXIT_FAILURE);
    ht_destroy(ht, NULL);
}

Test(ht_pop, null_parameters)
{
    char *key = "key";
    ht_t ht = {0};

    cr_assert_null(ht_pop(&ht, NULL));
    cr_assert_null(ht_pop(NULL, key));
    cr_assert_null(ht_pop(NULL, NULL));
}

Test(ht_pop, basic)
{
    int size = 10;
    int x = 42;
    char *key = "key";
    ht_t *ht = ht_create(hash, size);
    int index;

    cr_assert_not_null(ht);
    cr_assert_eq(ht_insert(ht, key, &x), EXIT_SUCCESS);
    index = hash(key, size);
    cr_assert_not_null(ht->buckets[index]);
    cr_assert_eq(ht_pop(ht, key), &x);
    cr_assert_null(ht->buckets[index]);
    ht_destroy(ht, NULL);
}

Test(ht_pop, two_values_in_same_bucket)
{
    int size = 10;
    int x = 42;
    int y = 24;
    char *key = "key";
    char *key2 = "kes";
    ht_t *ht = ht_create(hash, size);
    int index;

    cr_assert_not_null(ht);
    cr_assert_eq(ht_insert(ht, key, &x), EXIT_SUCCESS);
    cr_assert_eq(ht_insert(ht, key2, &y), EXIT_SUCCESS);
    index = hash(key, size);
    cr_assert_not_null(ht->buckets[index]);
    cr_assert_eq(ht_pop(ht, key), &x);
    cr_assert_not_null(ht->buckets[index]);
    ht_destroy(ht, NULL);
}

Test(ht_pop, pop_empty)
{
    int size = 10;
    char *key = "key";
    ht_t *ht = ht_create(hash, size);

    cr_assert_not_null(ht);
    cr_assert_null(ht_pop(ht, key));
    ht_destroy(ht, NULL);
}
