/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** linked_list
*/
/**
** @file linked_list
** @brief Header file for a generic single-linked list implementation.
**
** This file contains definitions, structures, and manipulation functions for
** a simple linked list container utilizing single-linked nodes.
**
** @author Daperkz
** @ingroup libdkz
** @test ./test/src/graph/simple/
** @version 1.0
** @date 2026-07-17
*/

#ifndef DKZ_LINKED_LIST_H_
    #define DKZ_LINKED_LIST_H_

    #include "node.h"

/*
** -_-
** STRUCTURES
** -_-
*/

/**
** @brief Structure representing the single-linked list container.
**/
typedef struct linked_list_s {
    node_t *head;
    int len;
} ll_t;

/*
** -_-
** LIFECYCLE
** -_-
*/

/**
** @brief Creates and allocates a new linked list container
**
** @return @b ll_t* Pointer to the newly allocated linked list structure.
** @retval NULL Returned if memory allocation fails.
**/
ll_t *ll_create(void);

/**
** @brief Destroys the linked list and frees all its internal memory
**
** @param[in, out] list Pointer to the linked list to destroy.
** @param[in] free_data Function pointer to free the stored generic data.
** If NULL, the generic data stored inside the nodes will not be freed.
**
** @return @b void
**/
void ll_destroy(ll_t *list, void (*free_data)(void *));

/*
** -_-
** MUTATIONS
** -_-
*/

/**
** @brief Appends a new node containing data to the end of the list
**
** @param[in, out] list Pointer to the linked list container.
** @param[in] data Pointer to the generic data to store.
**
** @return @b int Execution status.
** @retval 0 (EXIT_SUCCESS) On successful append.
** @retval 1 (EXIT_FAILURE) If list is NULL or if memory allocation fails.
**/
int ll_append(ll_t *list, void *data);

/**
** @brief Inserts a new node containing data at the head of the list
**
** @param[in, out] list Pointer to the linked list container.
** @param[in] data Pointer to the generic data to store.
**
** @return @b int Execution status.
** @retval 0 (EXIT_SUCCESS) On successful insertion.
** @retval 1 (EXIT_FAILURE) If list is NULL or if memory allocation fails.
**/
int ll_insert(ll_t *list, void *data);

/*
** -_-
** TRAVERSAL & SEARCH
** -_-
*/

/**
** @brief Retrieves the generic data pointer matching
** the reference and comparison
**
** @param[in] list Pointer to the linked list container.
** @param[in] ref Reference data or key to compare against.
** @param[in] cmp Comparison function pointer returning 0 on match.
**
** @return @b void* Pointer to the matching generic data.
** @retval NULL Returned if list is NULL, cmp is NULL, or no match is found.
**/
void *ll_get(ll_t *list, void *ref, int (*cmp)(void *, void *));

/**
** @brief Dumps the content of the linked list to stdout using a custom dumper
**
** Prints each node's index and visualizes the associated value
** using the provided @p dump_data function pointer.
**
** @param[in] list Pointer to the linked list container.
** @param[in] dump_data Function pointer to output the stored generic data.
**
** @return @b void
**/
void ll_dump(ll_t *list, void (*dump_data)(void *));

/*
** -_-
** REMOVAL
** -_-
*/

/**
** @brief Removes the head node from the list and returns its data
**
** @param[in, out] list Pointer to the linked list container.
**
** @return @b void* Pointer to the generic data of the removed head.
** @retval NULL Returned if list is NULL or empty.
**/
void *ll_pop_head(ll_t *list);

/**
** @brief Removes a node matching the reference and comparison,
** returning its data
**
** @param[in, out] list Pointer to the linked list container.
** @param[in] ref Reference data or key to compare against.
** @param[in] cmp Comparison function pointer returning 0 on match.
**
** @return @b void* Pointer to the generic data of the popped node.
** @retval NULL Returned if list is NULL, cmp is NULL, or no match is found.
**/
void *ll_pop(ll_t *list, void *ref, int (*cmp)(void *, void *));

#endif /* !DKZ_SIMPLE_LINKED_LIST_H_ */
