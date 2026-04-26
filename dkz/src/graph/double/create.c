/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** create
*/

#include <stdlib.h>

#include "dkz/graph/double_linked_list.h"

dll_t *dll_create(void)
{
    dll_t *list = malloc(sizeof(dll_t));

    if (!list)
        return (NULL);
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
    return (list);
}
