/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** displays, one-by-one, the characters of a string
*/

#include <unistd.h>

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    write(1, str, i);
}
