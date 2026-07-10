/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** write_wrapper
*/

#include "test.h"

// This flag controls whether read should fail or succeed
static int should_write_fail = BASE_SYSCALL_FAIL;
static int write_count_until_fail = BASE_SYSCALL_COUNT;

void set_write_fail(int should_fail)
{
    should_write_fail = should_fail;
}

void set_write_count(int count)
{
    write_count_until_fail = count;
}

// my wrapper
ssize_t __wrap_write(int __fd, const void *__buf, size_t __nbytes)
{
    int *fail = &should_write_fail;
    int *count = &write_count_until_fail;

    if (*fail) {
        if (*count == 0)
            return -1;
        if (*count > 0)
            (*count)--;
    }
    return __real_write(__fd, __buf, __nbytes);
}

void reset_write_wrapper(void)
{
    should_write_fail = BASE_SYSCALL_FAIL;
    write_count_until_fail = BASE_SYSCALL_COUNT;
}
