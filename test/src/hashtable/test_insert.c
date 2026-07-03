/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_insert
*/

#include "test.h"

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
