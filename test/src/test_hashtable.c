/*
** EPITECH PROJECT, 2026
** test_hashtable.c
** File description:
** test_hashtable
*/

#include <criterion/criterion.h>
#include <string.h>
#include <stdlib.h>

#include "my/hashtable.h"

static void free_content(void *data)
{
    free(data);
}

Test(hashtable, create_and_insert)
{
    ht_t *ht = ht_create(&hash, 10);
    char *val = strdup("High Performance");
    char *retrieved = NULL;

    cr_assert_not_null(ht);
    cr_assert_eq(ht_insert(ht, "project", val), 0);
    retrieved = ht_get(ht, "project");
    cr_assert_str_eq(retrieved, "High Performance");
    ht_destroy(ht, &free_content);
}

Test(hashtable, collision_handling)
{
    ht_t *ht = ht_create(&hash, 2);

    ht_insert(ht, "key1", "data1");
    ht_insert(ht, "key2", "data2");
    ht_insert(ht, "key3", "data3");
    cr_assert_str_eq(ht_get(ht, "key1"), "data1");
    cr_assert_str_eq(ht_get(ht, "key2"), "data2");
    cr_assert_str_eq(ht_get(ht, "key3"), "data3");
    ht_destroy(ht, NULL);
}

Test(hashtable, pop_logic)
{
    ht_t *ht = ht_create(&hash, 10);
    void *popped = NULL;

    ht_insert(ht, "temp", "to_be_popped");

    popped = ht_pop(ht, "temp");
    cr_assert_str_eq(popped, "to_be_popped");
    cr_assert_null(ht_get(ht, "temp"));
    ht_destroy(ht, NULL);
}

Test(hashing, hash_consistency)
{
    char *key = "Epitech";
    int h1 = djb2(key, strlen(key));
    int h2 = djb2(key, strlen(key));

    cr_assert_eq(h1, h2);
}
