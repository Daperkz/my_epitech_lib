/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** bucket
*/

#include <stdlib.h>

#include "dkz/string.h"
#include "dkz/hashtable.h"

ht_buckets_t *bucket_create(char *key, void *data)
{
    ht_buckets_t *bucket = malloc(sizeof(ht_buckets_t));

    if (!bucket)
        return (NULL);
    bucket->key = my_strdup(key);
    bucket->data = data;
    return (bucket);
}

void *bucket_destroy(ht_buckets_t *bucket)
{
    void *data = NULL;

    if (!bucket)
        return (NULL);
    if (bucket->key)
        free(bucket->key);
    data = bucket->data;
    free(bucket);
    return (data);
}
