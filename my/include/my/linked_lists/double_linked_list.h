/*
** EPITECH PROJECT, 2026
** double_linked_list.h
** File description:
** double
*/

#ifndef DOUBLE_LINKED_LIST_H_
    #define DOUBLE_LINKED_LIST_H_

    #include "node.h"
typedef struct double_linked_list_s {
    dnode_t *head;
    dnode_t *tail;
    int len;
} dll_t;

dll_t *dll_create(void);
void dll_destroy(dll_t *list, void (*free_data)(void *));

int dll_append(dll_t *list, void *data);
int dll_insert(dll_t *list, void *data);

dnode_t *dll_get(dll_t *list, void *ref, int (*cmp)(void *, void *));
dnode_t *dll_pop(dll_t *list, void *ref, int (*cmp)(void *, void *));

#endif /* !DOUBLE_LINKED_LIST_H_ */