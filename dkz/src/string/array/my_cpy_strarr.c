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
    int size = 0;
    char **new_strarr = NULL;

    if (!strarr)
        return (NULL);
    size = my_len_strarr(strarr);
    new_strarr = malloc(sizeof(char *) * (size + 1));
    if (!new_strarr)
        return (NULL);
    for (int i = 0; i < size; i++) {
        new_strarr[i] = my_strdup(strarr[i]);
        if (!new_strarr[i]) {
            new_strarr[i] = NULL;
            my_free_strarr(new_strarr);
            return NULL;
        }
    }
    new_strarr[size] = NULL;
    return new_strarr;
}
