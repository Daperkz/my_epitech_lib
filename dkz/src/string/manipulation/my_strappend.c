/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_strappend
*/

#include <unistd.h>
#include <stdlib.h>

#include "dkz/string.h"

char *my_strappend(char **dest_p, char *src)
{
    char *new_dest = NULL;
    char *origin = new_dest;

    if (!dest_p || !src)
        return (NULL);
    new_dest = malloc(sizeof(char) *
        (my_strlen((*dest_p)) + my_strlen(src) + 1));
    if (!new_dest)
        return (NULL);
    origin = new_dest;
    my_strcpy(new_dest, *dest_p);
    free(*dest_p);
    my_strcat(new_dest, src);
    (*dest_p) = origin;
    return (*dest_p);
}
