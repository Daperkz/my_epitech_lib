/*
** EPITECH PROJECT, 2026
** queue.h
** File description:
** queue
*/

#ifndef QUEUE_H_
    #define QUEUE_H_

    #include "double_linked_list.h"

typedef dll_t queue_t;

#define queue_create() dll_create()
#define queue_enqueue(q, data) dll_insert(q, data)
#define queue_dequeue(q) dll_pop_queue(q)
#define queue_is_empty(q) ((q)->len == 0)


#endif /* !QUEUE_H_ */
