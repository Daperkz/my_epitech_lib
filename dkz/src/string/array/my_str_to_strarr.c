/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_str_to_strarr.c
** splits a string into words.
** Separators will all be non-alphanumeric characters.
** The function returns an array in which each cell contains the address of a
** string (representing a word).
** The last cell is null to terminate the array
*/

#include <stdlib.h>

#include "dkz/string.h"

static int nbr_words(char const *str, char const *seps)
{
    int in_word = 0;
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (!my_strchr(seps, str[i]) && !in_word) {
            in_word = 1;
            count++;
            continue;
        }
        if (my_strchr(seps, str[i])) {
            in_word = 0;
        }
    }
    return count;
}

static char *extract_word(char const *str, char const *seps, int *i_ptr)
{
    int start = *i_ptr;
    int len;

    while (str[*i_ptr] && !my_strchr(seps, str[*i_ptr]))
        (*i_ptr)++;
    len = *i_ptr - start;
    return my_strndup(&str[start], len);
}

static int skip_seps(char const *str, char const *seps, int *i_ptr)
{
    while (str[*i_ptr] && my_strchr(seps, str[*i_ptr]))
        (*i_ptr)++;
    return (*i_ptr);
}

char **my_str_to_strarr(char const *str, char const *seps)
{
    char **strarr = NULL;
    int wi = 0;

    if (!str || !seps)
        return NULL;
    strarr = malloc(sizeof(char *) * (nbr_words(str, seps) + 1));
    if (!strarr)
        return NULL;
    for (int i = 0; str[i]; wi++) {
        if (!str[skip_seps(str, seps, &i)])
            break;
        strarr[wi] = extract_word(str, seps, &i);
        if (!strarr[wi]) {
            my_free_strarr(strarr);
            return NULL;
        }
    }
    strarr[wi] = NULL;
    return strarr;
}
