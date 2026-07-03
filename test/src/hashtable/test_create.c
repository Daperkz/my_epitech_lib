/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_create
*/

#include "test.h"

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
