/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** malloc_wrapper
*/

#include "test.h"

// This flag controls whether malloc should fail or succeed
static int should_malloc_fail = BASE_MALLOC_FAIL;
static int malloc_count_until_fail = BASE_MALLOC_COUNT;

void set_malloc_fail(int should_fail)
{
    should_malloc_fail = should_fail;
}

void set_malloc_count(int count)
{
    malloc_count_until_fail = count;
}

// Our wrapper
void *__wrap_malloc(size_t size)
{
    int *fail = &should_malloc_fail;
    int *count = &malloc_count_until_fail;

    if (*fail) {
        if (*count == 0)
            return NULL;
        if (*count > 0)
            (*count)--;
    }
    return __real_malloc(size);
}

void reset_malloc_wrapper(void)
{
    should_malloc_fail = BASE_MALLOC_FAIL;
    malloc_count_until_fail = BASE_MALLOC_COUNT;
}
