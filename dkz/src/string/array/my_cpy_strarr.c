/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** my_copy_strarr
*/

#include <stdlib.h>

#include "dkz/string.h"

char **my_cpy_strarr(char *const *strarr)
{
    int i = 0;
    char **new_strarr = NULL;

    while (strarr && strarr[i])
        i++;
    new_strarr = malloc(sizeof(char *) * (i + 1));
    if (!new_strarr)
        return (NULL);
    for (int j = 0; j < i; j++) {
        new_strarr[j] = my_strdup(strarr[j]);
        if (!new_strarr[j]) {
            new_strarr[j] = NULL;
            my_free_strarr(new_strarr);
            return NULL;
        }
    }
    new_strarr[i] = NULL;
    return new_strarr;
}
