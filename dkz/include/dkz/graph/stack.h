/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** stack
*/

#ifndef DKZ_STACK_H_
    #define DKZ_STACK_H_

    #include "simple_linked_list.h"

typedef ll_t my_stack_t;

    #define STACK_CREATE() ll_create()
    #define STACK_DESTROY(q, free) ll_destroy(q, free)
    #define STACK_PUSH(s, data) ll_insert(s, data)
    #define STACK_POP(s) ll_pop_head(s)
    #define STACK_IS_EMPTY(s) ((s)->len == 0)

#endif /* !DKZ_STACK_H_ */
