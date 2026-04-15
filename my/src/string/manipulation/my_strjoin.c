/*
** EPITECH PROJECT, 2026
** my_strjoin.c
** File description:
** my_strjoin
*/

#include <stdlib.h>

#include "my/string.h"

char *my_strjoin(char *str1, char *str2)
{
    char *str;

    if (!str1 || !str2)
        return (NULL);
    str = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
    if (!str)
        return (NULL);
    my_strcpy(str, str1);
    my_strcat(str, str2);
    return (str);
}
