/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** queue
*/
/**
** @file queue.h
** @brief Header-only macro wrapper implementing a generic FIFO
** (First-In-First-Out) Queue.
**
** This file defines a queue type and operations entirely using macros mapped
** onto a double-linked list backend (@ref dll_t).
**
** @author Daperkz
** @ingroup libdkz
** @test ./test/src/graph/
** @version 1.0
** @date 2026-07-17
*/

#ifndef DKZ_QUEUE_H_
    #define DKZ_QUEUE_H_

    #include "double_linked_list.h"

/*
** -_-
** TYPES
** -_-
*/

/**
** @brief Type representing a generic queue container, aliasing @ref dll_t.
**/
typedef dll_t queue_t;

    /*
    ** -_-
    ** MACROS
    ** -_-
    */

    /**
    ** @brief Creates and allocates a new queue container
    **
    ** @return @b queue_t* Pointer to the newly allocated queue structure.
    ** @retval NULL Returned if memory allocation fails.
    **/
    #define QUEUE_CREATE() dll_create()

    /**
    ** @brief Destroys the queue and frees all its internal memory
    **
    ** @param[in, out] q Pointer to the queue to destroy (@ref queue_t*).
    ** @param[in] free Function pointer to free the stored generic data.
    ** If NULL, the generic data stored inside the elements will not be freed.
    **/
    #define QUEUE_DESTROY(q, free) dll_destroy(q, free)

    /**
    ** @brief Inserts a new element at the beginning of the queue (Enqueue)
    **
    ** @param[in, out] q Pointer to the queue container (@ref queue_t*).
    ** @param[in] data Pointer to the generic data to store.
    **
    ** @return @b int Execution status.
    ** @retval 0 (EXIT_SUCCESS) On successful enqueue.
    ** @retval 1 (EXIT_FAILURE) If q is NULL or if memory allocation fails.
    **/
    #define QUEUE_ENQUEUE(q, data) dll_insert(q, data)

    /**
    ** @brief Removes and returns the oldest element from the end of the queue
    ** (Dequeue)
    **
    ** @param[in, out] q Pointer to the queue container (@ref queue_t*).
    **
    ** @return @b void* Pointer to the generic data of the popped element.
    ** @retval NULL Returned if queue is NULL or empty.
    **/
    #define QUEUE_DEQUEUE(q) dll_pop_tail(q)

    /**
    ** @brief Checks if the queue contains zero elements
    **
    ** @param[in] q Pointer to the queue container (@ref queue_t*).
    **
    ** @return @b int Evaluates to 1 if empty, 0 otherwise.
    **/
    #define QUEUE_IS_EMPTY(q) ((q)->len == 0)

#endif /* !DKZ_QUEUE_H_ */
