/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** read_wrapper
*/

#include "test.h"

// This flag controls whether read should fail or succeed
static int should_read_fail = BASE_SYSCALL_FAIL;
static int read_count_until_fail = BASE_SYSCALL_COUNT;

void set_read_fail(int should_fail)
{
    should_read_fail = should_fail;
}

void set_read_count(int count)
{
    read_count_until_fail = count;
}

// my wrapper
ssize_t __wrap_read(int __fd, void *__buf, size_t __nbytes)
{
    int *fail = &should_read_fail;
    int *count = &read_count_until_fail;

    if (*fail) {
        if (*count == 0)
            return -1;
        if (*count > 0)
            (*count)--;
    }
    return __real_read(__fd, __buf, __nbytes);
}

void reset_read_wrapper(void)
{
    should_read_fail = BASE_SYSCALL_FAIL;
    read_count_until_fail = BASE_SYSCALL_COUNT;
}
