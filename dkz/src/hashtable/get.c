/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** get
*/

#include "dkz/macro.h"
#include "dkz/string.h"
#include "dkz/hashtable.h"

static int compare_keys(void *data, void *ref)
{
    return my_strcmp(((ht_buckets_t *)data)->key, (char *)ref);
}

void *ht_get(ht_t *ht, char *key)
{
    int index = 0;
    ht_buckets_t *entry = NULL;

    if (!ht || !key)
        return (NULL);
    index = ht->hash(key, ht->size);
    if (!ht->buckets[index])
        return (NULL);
    entry = (ht_buckets_t *)ll_get(ht->buckets[index], key, compare_keys);
    if (!entry)
        return (NULL);
    return (entry->data);
}
