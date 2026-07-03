/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_destroy
*/

#include "test.h"

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
