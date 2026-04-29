/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_free_strarr.c
** frees the word array
*/

#include <stdlib.h>

void my_free_strarr(char **strarr)
{
    if (!strarr)
        return;
    for (int i = 0; strarr[i]; i++) {
        free(strarr[i]);
    }
    free(strarr);
}
