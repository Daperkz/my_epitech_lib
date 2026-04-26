/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** create
*/

#include <stdlib.h>

#include "dkz/graph/simple_linked_list.h"

ll_t *ll_create(void)
{
    ll_t *list = malloc(sizeof(ll_t));

    if (!list)
        return (NULL);
    list->head = NULL;
    list->len = 0;
    return (list);
}
