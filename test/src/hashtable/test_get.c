/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_get
*/

#include "test.h"

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
