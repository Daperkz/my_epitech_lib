/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** stat_wrapper
*/

#include "test.h"

// This flag controls whether read should fail or succeed
static int should_stat_fail = BASE_SYSCALL_FAIL;
static int stat_count_until_fail = BASE_SYSCALL_COUNT;

void set_stat_fail(int should_fail)
{
    should_stat_fail = should_fail;
}

void set_stat_count(int count)
{
    stat_count_until_fail = count;
}

// my wrapper
int __wrap_stat(
    const char *__restrict__ __file, struct stat *__restrict__ __buf)
{
    int *fail = &should_stat_fail;
    int *count = &stat_count_until_fail;

    if (*fail) {
        if (*count == 0)
            return -1;
        if (*count > 0)
            (*count)--;
    }
    return __real_stat(__file, __buf);
}

void reset_stat_wrapper(void)
{
    should_stat_fail = BASE_SYSCALL_FAIL;
    stat_count_until_fail = BASE_SYSCALL_COUNT;
}
