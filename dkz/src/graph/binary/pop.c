/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** pop
*/

#include <stdlib.h>

#include "dkz/graph/binary_tree.h"

static bnode_t **find_node_ptr(bnode_t **root, void *ref,
    int (*cmp)(void *, void *))
{
    bnode_t **curr = root;
    int res = 0;

    while (*curr) {
        res = cmp(ref, (*curr)->data);
        if (res == 0)
            return (curr);
        if (res < 0)
            curr = &(*curr)->left;
        if (res > 0)
            curr = &(*curr)->right;
    }
    return (NULL);
}

static void extract_node(bnode_t **target)
{
    bnode_t *to_free = *target;
    bnode_t **succ = NULL;

    if (!to_free->left) {
        *target = to_free->right;
        free(to_free);
        return;
    }
    if (!to_free->right) {
        *target = to_free->left;
        free(to_free);
        return;
    } else {
        for (succ = &to_free->right; (*succ)->left; succ = &(*succ)->left);
        to_free->data = (*succ)->data;
        to_free = *succ;
        *succ = to_free->right;
        free(to_free);
    }
}

void *btree_pop(btree_t *tree, void *ref, int (*cmp)(void *, void *))
{
    bnode_t **target = NULL;
    void *data = NULL;

    if (!tree || !tree->root || !cmp)
        return (NULL);
    target = find_node_ptr(&tree->root, ref, cmp);
    if (!target)
        return (NULL);
    data = (*target)->data;
    extract_node(target);
    tree->size--;
    return (data);
}
