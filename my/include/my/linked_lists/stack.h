/*
** EPITECH PROJECT, 2026
** stack.h
** File description:
** stack
*/

#ifndef STACK_H_
    #define STACK_H_

    #include "simple_linked_list.h"

typedef ll_t stack_t;

#define stack_create() ll_create()
#define stack_push(s, data) ll_insert(s, data)
#define stack_pop(s) ll_pop_head(s)
#define stack_is_empty(s) ((s)->len == 0)

#endif /* !STACK_H_ */
