/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** prints out a string
*/

#include <unistd.h>
#include "my_strlen.h"
#include "count_error.h"


void my_putstr(int fd, char *str, cot_err_t *coterr)
{
    int strlen = my_strlen(str);

    if (write(fd, str, strlen) == strlen) {
        coterr->count += strlen;
    } else {
        coterr->error = 1;
    }
}
