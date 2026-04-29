/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** my_put_strarr
*/

#include "dkz/io.h"
#include "dkz/string.h"

void my_put_strarr(char *const *strarr, char sep)
{
    while (strarr && *strarr) {
        my_putstr(*strarr);
        my_putchar(sep);
        strarr++;
    }
}
