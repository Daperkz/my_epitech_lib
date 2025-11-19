/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** displays, one-by-one, the characters of a string
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    const char *start = str;

    if (!str) {
        return -1;
    }
    while (*str) {
        str++;
    }
    return write(1, start, (str - start));
}
