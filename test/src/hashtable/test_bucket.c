/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_bucket
*/

#include "test.h"

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
