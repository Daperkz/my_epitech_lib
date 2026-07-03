/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_pop
*/

#include "test.h"

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
