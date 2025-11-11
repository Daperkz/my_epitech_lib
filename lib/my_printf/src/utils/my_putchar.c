/*
** EPITECH PROJECT, 2025
** my_putchar
** File description:
** writes only 1 char
*/

#include <unistd.h>
#include "count_error.h"

void my_putchar(int fd, char c, cot_err_t *coterr)
{
    if (write(fd, &c, 1) == 1) {
        coterr->count += 1;
    } else {
        coterr->error = 1;
    }
}
