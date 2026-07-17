/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** hashtable.h
*/
/**
** @file hashtable.h
** @brief Header file for hashtable structures and operations.
**
** This file contains the definitions, structures, hash algorithms, and
** manipulation functions for a generic hashtable implementation using
** chained linked lists for collision resolution.
**
** @author Daperkz
** @ingroup libdkz
** @test ./test/src/hashtable/
** @version 1.0
** @date 2026-07-16
*/

#ifndef DKZ_HASHTABLE_H
    #define DKZ_HASHTABLE_H

    #include "graph/linked_list.h"

/*
** -_-
** STRUCTURES
** -_-
*/

/**
** @brief Structure representing a single key-value bucket in the hashtable.
**/
typedef struct ht_buckets_s {
    char *key;
    void *data;
} ht_buckets_t;


/**
** @brief Structure representing the hashtable container.
**/
typedef struct hashtable_s {
    int (*hash)(char *, int);
    int size;
    ll_t **buckets;
} ht_t;

/*
** -_-
** BUCKET UTILS
** -_-
*/

/**
** @brief Creates and allocates a new hashtable bucket
**
** @param[in] key The unique string identifier.
** @param[in] data Pointer to the generic data to associate with the @p key.
**
** @return @b ht_buckets_t* Pointer to the newly allocated bucket structure.
** @retval NULL Returned if memory allocation fails.
**/
ht_buckets_t *bucket_create(char *key, void *data);

/**
** @brief Destroys and frees a single hashtable bucket
**
** @note This function only frees the bucket structure and its key.
** It returns the raw data pointer so the caller can decide how to free it.
**
** @param[in] bucket Pointer to the bucket to destroy.
**
** @return @b void* Pointer to the generic @p data
** that was stored in the bucket.
** @retval NULL Returned if @p bucket is NULL.
**/
void *bucket_destroy(ht_buckets_t *bucket);

/*
** -_-
** HASH FUNCTIONS
** -_-
*/

/**
** @brief Generates a hash value using the SDBM algorithm
**
** @param[in] key The string key to hash.
** @param[in] len The maximum size boundaries (usually the hashtable size).
**
** @return @b int The calculated index within bounds.
**/
int sdbm(char *key, int len);

/**
** @brief Generates a hash value using the FNV-1a (Fowler-Noll-Vo) algorithm
**
** @param[in] key The string key to hash.
** @param[in] len The maximum size boundaries (usually the hashtable size).
**
** @return @b int The calculated index within bounds.
**/
int fnv_1a(char *key, int len);

/**
** @brief Generates a hash value using the DJB2 algorithm
**
** @param[in] key The string key to hash.
** @param[in] len The maximum size boundaries (usually the hashtable size).
**
** @return @b int The calculated index within bounds.
**/
int djb2(char *key, int len);

/**
** @brief Generates a hash value using the fnv_1a algorithm
**
** @param[in] key The string key to hash.
** @param[in] len The maximum size boundaries (usually the hashtable size).
**
** @return @b int The calculated index within bounds.
**/
int hash(char *key, int len);

/*
** -_-
** TABLE MANAGEMENT
** -_-
*/

/**
** @brief Creates and allocates a new hashtable structure
**
** @param[in] hash Function pointer to the hashing algorithm to use.
** @param[in] size The total amount of buckets to allocate.
**
** @return @b ht_t* Pointer to the newly allocated hashtable structure.
** @retval NULL Returned if memory allocation fails or @p hash is NULL.
**/
ht_t *ht_create(int (*hash)(char *, int), int size);

/**
** @brief Destroys the hashtable and frees all its internal memory
**
** @param[in, out] ht Pointer to the hashtable to destroy.
** @param[in] free_data Function pointer to free the stored generic data.
** If NULL, the generic data stored inside the buckets will not be freed.
**
** @return @b void
**/
void ht_destroy(ht_t *ht, void (*free_data)(void *));

/*
** -_-
** TABLE OPERATIONS
** -_-
*/

/**
** @brief Inserts a key-value pair into the hashtable
**
** If the key already exists, its associated data is updated. Otherwise,
** a new bucket is appended to the corresponding list index.
**
** @param[in, out] ht Pointer to the hashtable structure.
** @param[in] key The unique key string to insert.
** @param[in] data Pointer to the generic data to store.
**
** @return @b int Execution status.
** @retval 0 (EXIT_SUCCESS) On successful insertion.
** @retval 1 (EXIT_FAILURE) If an error occurs or if memory allocation fails.
**/
int ht_insert(ht_t *ht, char *key, void *data);

/**
** @brief Removes a key-value pair from the hashtable and returns the data
**
** @param[in, out] ht Pointer to the hashtable structure.
** @param[in] key The key string to look for.
**
** @return @b void* Pointer to the generic data of the removed key.
** @retval NULL Returned if @p ht is NULL, or if @p key is not found.
**/
void *ht_pop(ht_t *ht, char *key);

/**
** @brief Retrieves the generic data pointer associated with a key
**
** @param[in] ht Pointer to the hashtable structure.
** @param[in] key The key string to look for.
**
** @return @b void* Pointer to the associated generic data.
** @retval NULL Returned if @p ht is NULL, or if @p key is not found.
**/
void *ht_get(ht_t *ht, char *key);

/**
** @brief Dumps the content of the hashtable to stdout using a custom dumper
**
** Prints each bucket index, key, and visualizes the associated value
** using the provided @p dump_data function pointer.
**
** @param[in] ht Pointer to the hashtable structure.
** @param[in] dump_data Function pointer to output the stored generic data.
**
** @return @b void
**/
void ht_dump(ht_t *ht, void (*dump_data)(void *));

#endif /* DKZ_HASHTABLE_H */
