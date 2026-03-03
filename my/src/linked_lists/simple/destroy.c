/*
** EPITECH PROJECT, 2026
** destroy.c
** File description:
** destroy
*/

#include <stdlib.h>

#include "my/linked_lists/simple_linked_list.h"

void ll_destroy(ll_t *list, void (*free_data)(void *))
{
    node_t *current = NULL;
    node_t *next = NULL;

    if (!list)
        return;
    current = list->head;
    for (int i = 0; i < list->len; i++) {
        next = current->next;
        list->head = current->next;
        destroy_node(current, free_data);
        current = next;
    }
    free(list);
}
