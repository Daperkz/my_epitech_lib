/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** stack
*/
/**
** @file stack.h
** @brief Header-only macro wrapper implementing a generic LIFO
** (Last-In-First-Out) Stack.
**
** This file defines a stack type and operations entirely using macros mapped
** onto a single-linked list backend (@ref ll_t).
**
** @author Daperkz
** @ingroup libdkz
** @test ./test/src/graph/
** @version 1.0
** @date 2026-07-17
*/

#ifndef DKZ_STACK_H_
    #define DKZ_STACK_H_

    #include "linked_list.h"

/*
** -_-
** TYPES
** -_-
*/

/**
** @brief Type representing a generic stack container, aliasing @ref ll_t.
**/
typedef ll_t my_stack_t;

    /*
    ** -_-
    ** MACROS
    ** -_-
    */

    /**
    ** @brief Creates and allocates a new stack container
    **
    ** @return @b my_stack_t* Pointer to the newly allocated stack structure.
    ** @retval NULL Returned if memory allocation fails.
    **/
    #define STACK_CREATE() ll_create()

    /**
    ** @brief Destroys the stack and frees all its internal memory
    **
    ** @param[in, out] q Pointer to the stack to destroy (@ref my_stack_t*).
    ** @param[in] free Function pointer to free the stored generic data.
    ** If NULL, the generic data stored inside the elements will not be freed.
    **/
    #define STACK_DESTROY(q, free) ll_destroy(q, free)

    /**
    ** @brief Pushes a new element onto the top of the stack (Push)
    **
    ** @param[in, out] s Pointer to the stack container (@ref my_stack_t*).
    ** @param[in] data Pointer to the generic data to store.
    **
    ** @return @b int Execution status.
    ** @retval 0 (EXIT_SUCCESS) On successful push.
    ** @retval 1 (EXIT_FAILURE) If s is NULL or if memory allocation fails.
    **/
    #define STACK_PUSH(s, data) ll_insert(s, data)

    /**
    ** @brief Removes and returns the top element from the stack (Pop)
    **
    ** @param[in, out] s Pointer to the stack container (@ref my_stack_t*).
    **
    ** @return @b void* Pointer to the generic data of the popped element.
    ** @retval NULL Returned if stack is NULL or empty.
    **/
    #define STACK_POP(s) ll_pop_head(s)

    /**
    ** @brief Checks if the stack contains zero elements
    **
    ** @param[in] s Pointer to the stack container (@ref my_stack_t*).
    **
    ** @return @b int Evaluates to 1 if empty, 0 otherwise.
    **/
    #define STACK_IS_EMPTY(s) ((s)->len == 0)

#endif /* !DKZ_STACK_H_ */
