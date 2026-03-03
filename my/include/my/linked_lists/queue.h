/*
** EPITECH PROJECT, 2026
** queue.h
** File description:
** queue
*/

#ifndef QUEUE_H_
    #define QUEUE_H_

    #include "simple_linked_list.h"

typedef ll_t queue_t;

#define queue_create() ll_create()
#define queue_enqueue(q, data) ll_append(q, data)
#define queue_dequeue(q) ll_pop_front(q)
#define queue_is_empty(q) ((q)->len == 0)


#endif /* !QUEUE_H_ */
