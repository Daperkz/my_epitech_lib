/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** binary_tree
*/
/**
** @file binary_tree.h
** @brief Header file for a generic binary tree implementation.
**
** This file contains definitions, structures, and manipulation functions for
** a binary tree container utilizing binary nodes.
**
** @author Daperkz
** @ingroup libdkz
** @test ./test/src/graph/binary/
** @version 1.0
** @date 2026-07-17
*/

#ifndef DKZ_BINARY_TREE_H_
    #define DKZ_BINARY_TREE_H_

    #include "node.h"

/*
** -_-
** STRUCTURES
** -_-
*/

/**
** @brief Structure representing the binary tree container.
**/
typedef struct binary_tree_s {
    bnode_t *root;
    int depth; /**< Note: This value is currently not calculated or updated **/
    int size;
} btree_t;

/*
** -_-
** LIFECYCLE
** -_-
*/

/**
** @brief Creates and allocates a new binary tree container
**
** @return @b btree_t* Pointer to the newly allocated binary tree structure.
** @retval NULL Returned if memory allocation fails.
**/
btree_t *btree_create(void);

/**
** @brief Destroys the binary tree and recursively frees all its internal memory
**
** @param[in, out] tree Pointer to the binary tree to destroy.
** @param[in] free_data Function pointer to free the stored generic data.
** If NULL, the generic data stored inside the nodes will not be freed.
**
** @return @b void
**/
void btree_destroy(btree_t *tree, void (*free_data)(void *));

/*
** -_-
** OPERATIONS
** -_-
*/

/**
** @brief Inserts a new element into the binary tree based on
** a comparison function
**
** @param[in, out] tree Pointer to the binary tree container.
** @param[in] data Pointer to the generic data to insert.
** @param[in] cmp Comparison function pointer. Returns negative if left,
** positive if right, or 0 if equal (behavior on 0 depends on implementation).
**
** @return @b int Execution status.
** @retval 0 (EXIT_SUCCESS) On successful insertion.
** @retval 1 (EXIT_FAILURE) If @p tree or @p cmp is NULL, or if a memory
** allocation failure occurs.
**/
int btree_insert(btree_t *tree, void *data, int (*cmp)(void *, void *));

/**
** @brief Searches for and retrieves data matching
** a reference pointer in the tree
**
** @param[in] tree Pointer to the binary tree container.
** @param[in] ref Reference data or key to look for.
** @param[in] cmp Comparison function pointer.
**
** @return @b void* Pointer to the matching generic data.
** @retval NULL Returned if @p tree or @p cmp is NULL,
** or if the key is not found.
**/
void *btree_get(btree_t *tree, void *ref, int (*cmp)(void *, void *));

/**
** @brief Removes an element matching the reference from the tree and
** returns its data
**
** @note This function is currently not implemented (to be done).
**
** @param[in, out] tree Pointer to the binary tree container.
** @param[in] ref Reference data or key to pop.
** @param[in] cmp Comparison function pointer.
**
** @return @b void* Pointer to the popped generic data.
** @retval NULL Returned if @p tree or @p cmp is NULL,
** or if the key is not found.
**/
void *btree_pop(btree_t *tree, void *ref, int (*cmp)(void *, void *));

#endif /* !DKZ_BINARY_TREE_H_ */
