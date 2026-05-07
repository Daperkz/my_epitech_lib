/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test
*/

#ifndef LIBDKZ_TEST_H_
    #define LIBDKZ_TEST_H_

    #include <stdlib.h>

    #include "../../dkz/include/dkz.h"

// The "real" malloc provided by the system
void *__real_malloc(size_t size);

void reset_malloc_wrapper(void);
void set_malloc_count(int count);
void set_malloc_fail(int should_fail);

#endif /* !LIBDKZ_TEST_H_ */
