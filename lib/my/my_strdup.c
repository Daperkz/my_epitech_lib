/*
** EPITECH PROJECT, 2025
** my_strdup
** File description:
** allocates memory and copies the string given as argument in it.
*/

#include <stdlib.h>

#include "my_strdup_tools.h"

char *my_strdup(char const *src)
{
    char *ptr = malloc(my_strlen(src) + 1);

    while (*src != '\0') {
        *ptr = *src;
        src++;
        ptr++;
    }
    *ptr = '\0';
    return ptr;
}
