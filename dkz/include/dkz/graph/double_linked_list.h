/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** double
*/
/**
** @file double_linked_list.h
** @brief Header file for a generic double-linked list implementation.
**
** This file contains definitions, structures, and manipulation functions for
** a double-linked list container utilizing double-linked nodes.
**
** @author Daperkz
** @ingroup libdkz
** @test ./test/src/graph/double/
** @version 1.0
** @date 2026-07-17
*/

#ifndef DKZ_DOUBLE_LINKED_LIST_H_
    #define DKZ_DOUBLE_LINKED_LIST_H_

    #include "node.h"

    /*
** -_-
** STRUCTURES
** -_-
*/

/**
** @brief Structure representing the double-linked list container.
**/
typedef struct double_linked_list_s {
    dnode_t *head;
    dnode_t *tail;
    int len;
} dll_t;

/*
** -_-
** LIFECYCLE
** -_-
*/

/**
** @brief Creates and allocates a new double-linked list container
**
** @return @b dll_t* Pointer to the newly allocated
** double-linked list structure.
** @retval NULL Returned if memory allocation fails.
**/
dll_t *dll_create(void);

/**
** @brief Destroys the double-linked list and frees all its internal memory
**
** @param[in, out] list Pointer to the double-linked list to destroy.
** @param[in] free_data Function pointer to free the stored generic data.
** If NULL, the generic data stored inside the nodes will not be freed.
**
** @return @b void
**/
void dll_destroy(dll_t *list, void (*free_data)(void *));

/*
** -_-
** MUTATIONS
** -_-
*/

/**
** @brief Appends a new node containing data to the tail of the list
**
** @param[in, out] list Pointer to the double-linked list container.
** @param[in] data Pointer to the generic data to store.
**
** @return @b int Execution status.
** @retval 0 (EXIT_SUCCESS) On successful append.
** @retval 1 (EXIT_FAILURE) If list is NULL or if memory allocation fails.
**/
int dll_append(dll_t *list, void *data);

/**
** @brief Inserts a new node containing data at the head of the list
**
** @param[in, out] list Pointer to the double-linked list container.
** @param[in] data Pointer to the generic data to store.
**
** @return @b int Execution status.
** @retval 0 (EXIT_SUCCESS) On successful insertion.
** @retval 1 (EXIT_FAILURE) If list is NULL or if memory allocation fails.
**/
int dll_insert(dll_t *list, void *data);

/*
** -_-
** REMOVAL
** -_-
*/

/**
** @brief Removes the head node from the list and returns its data
**
** @param[in, out] list Pointer to the double-linked list container.
**
** @return @b void* Pointer to the generic data of the removed head.
** @retval NULL Returned if list is NULL or empty.
**/
void *dll_pop_head(dll_t *list);

/**
** @brief Removes the tail node from the list and returns its data
**
** @param[in, out] list Pointer to the double-linked list container.
**
** @return @b void* Pointer to the generic data of the removed tail.
** @retval NULL Returned if list is NULL or empty.
**/
void *dll_pop_tail(dll_t *list);

/**
** @brief Removes a node matching the reference and comparison,
** returning its data
**
** Handles the re-linking of neighboring nodes gracefully.
**
** @param[in, out] list Pointer to the double-linked list container.
** @param[in] ref Reference data or key to compare against.
** @param[in] cmp Comparison function pointer returning 0 on match.
**
** @return @b void* Pointer to the generic data of the popped node.
** @retval NULL Returned if list is NULL, cmp is NULL, or no match is found.
**/
void *dll_pop(dll_t *list, void *ref, int (*cmp)(void *, void *));

/*
** -_-
** TRAVERSAL & SEARCH
** -_-
*/

/**
** @brief Dumps the content of the double-linked list to stdout using
** a custom dumper
**
** Prints each node's index (traversing from head to tail) and visualizes the
** associated value using the provided @p dump_data function pointer.
**
** @param[in] list Pointer to the double-linked list container.
** @param[in] dump_data Function pointer to output the stored generic data.
**
** @return @b void
**/
void dll_dump(dll_t *list, void (*dump_data)(void *));

/**
** @brief Retrieves the generic data pointer matching
** the reference and comparison
**
** @param[in] list Pointer to the double-linked list container.
** @param[in] ref Reference data or key to compare against.
** @param[in] cmp Comparison function pointer returning 0 on match.
**
** @return @b void* Pointer to the matching generic data.
** @retval NULL Returned if list is NULL, cmp is NULL, or no match is found.
**/
void *dll_get(dll_t *list, void *ref, int (*cmp)(void *, void *));

#endif /* !DKZ_DOUBLE_LINKED_LIST_H_ */
