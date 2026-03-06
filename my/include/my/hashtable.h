/*
** EPITECH PROJECT, 2026
** G-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H

    #include "simple_linked_list.h"

typedef struct ht_buckets_s {
    char *key;
    void *value;
} ht_buckets_t;

typedef struct hashtable_s {
    int (*hash)(char *, int);
    int size;
    ll_t **buckets;
} ht_t;

// Hash function
int sdbm(char *key);
int fnv_1a(char *key);
int djb2(char *key);
int hash(char *key, int len);

// Create & destro table
ht_t *ht_create(int (*hash)(char *, int), int len);
void ht_destroy(ht_t *ht);

// Handle table
int ht_insert(ht_t *ht, char *key, void *data);
int ht_delete(ht_t *ht, char *key);
char *ht_search(ht_t *ht, char *key);
void ht_dump(ht_t *ht, void (*dump_data)(void *));

#endif /* HASHTABLE_H */
