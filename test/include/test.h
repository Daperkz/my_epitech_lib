/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test
*/

#ifndef LIBDKZ_TEST_H_
    #define LIBDKZ_TEST_H_


    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <fcntl.h>
    #include <sys/stat.h>

    #include <criterion/criterion.h>
    #include <criterion/redirect.h>

    #include "../../dkz/include/dkz.h"

    #define BASE_SYSCALL_FAIL 0
    #define BASE_SYSCALL_COUNT -1

// The "real" malloc provided by the system
void *__real_malloc(size_t size);

// my wrapper
void *__wrap_malloc(size_t size);

void reset_malloc_wrapper(void);
void set_malloc_count(int count);
void set_malloc_fail(int should_fail);

// The "real" read provided by the system
ssize_t __real_read(int __fd, void *__buf, size_t __nbytes);

// my wrapper
ssize_t __wrap_read(int __fd, void *__buf, size_t __nbytes);

void reset_read_wrapper(void);
void set_read_count(int count);
void set_read_fail(int should_fail);

// The "real" stat provided by the system
int __real_stat(
    const char *__restrict__ __file, struct stat *__restrict__ __buf
);

// my wrapper
int __wrap_stat(
    const char *__restrict__ __file, struct stat *__restrict__ __buf
);

void reset_stat_wrapper(void);
void set_stat_count(int count);
void set_stat_fail(int should_fail);


#endif /* !LIBDKZ_TEST_H_ */
