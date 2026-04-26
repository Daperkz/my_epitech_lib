/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** get
*/

#include "dkz/macro.h"

#include "dkz/graph/simple_linked_list.h"

void *ll_get(ll_t *list, void *ref, int (*cmp)(void *, void *))
{
    node_t *tmp = NULL;

    if (!list || !cmp)
        return (NULL);
    tmp = list->head;
    while (tmp) {
        if (cmp(tmp->data, ref) == 0)
            return (tmp->data);
        tmp = tmp->next;
    }
    return (NULL);
}
