/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** binary_tree
*/

#ifndef DKZ_BINARY_TREE_H_
    #define DKZ_BINARY_TREE_H_

    #include "node.h"

typedef struct binary_tree_s {
    bnode_t *root;
    int depth; // isn't calculated
    int size;
} btree_t;

btree_t *btree_create(void);
void btree_destroy(btree_t *tree, void (*free_data)(void *));

int btree_insert(btree_t *tree, void *data, int (*cmp)(void *, void *));
void *btree_get(btree_t *tree, void *ref, int (*cmp)(void *, void *));

// to be done
void *btree_pop(btree_t *tree, void *ref, int (*cmp)(void *, void *));

#endif /* !DKZ_BINARY_TREE_H_ */
