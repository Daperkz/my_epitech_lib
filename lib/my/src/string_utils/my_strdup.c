/*
** EPITECH PROJECT, 2025
** my_strdup
** File description:
** allocates memory and copies the string given as argument in it.
*/

#include <stdlib.h>

#include "string_utils.h"

char *my_strdup(char const *src)
{
    char *ptr = malloc(my_strlen(src) + 1);
    char *origin = ptr;

    if (ptr == NULL) {
        return NULL;
    }
    while (*src != '\0') {
        *ptr = *src;
        src++;
        ptr++;
    }
    *ptr = '\0';
    return origin;
}
