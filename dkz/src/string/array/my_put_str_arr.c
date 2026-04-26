/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** my_put_str_arr
*/

#include "dkz/io.h"
#include "dkz/string.h"

void my_put_str_arr(char *const *str_arr, char sep)
{
    while (*str_arr) {
        my_putstr(*str_arr);
        my_putchar(sep);
        str_arr++;
    }
}
