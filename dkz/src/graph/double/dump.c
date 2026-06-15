/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** dump
*/

#include "dkz/macro.h"

#include "dkz/graph/double_linked_list.h"

void dll_dump(dll_t *list, void (*dump_data)(void *))
{
    dnode_t *current = NULL;

    if (!list)
        return;
    current = list->head;
    while (current) {
        if (dump_data)
            dump_data(current->data);
        current = current->next;
    }
}
