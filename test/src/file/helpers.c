/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** helpers
*/

#include "test.h"

void create_test_file(const char *name, const char *content)
{
    int fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd != -1) {
        write(fd, content, strlen(content));
        close(fd);
    }
}
