/*
** EPITECH PROJECT, 2025
** my_str_to_word_array
** File description:
** splits a string into words.
** Separators will all be non-alphanumeric characters.
** The function returns an array in which each cell contains the address of a
** string (representing a word).
** The last cell is null to terminate the array
*/

// possibilité d'itérée sur la suite du str au lieu de recommencer à zero à
// chaque fois

#include <stdlib.h>

#include "string_utils.h"

static int is_alphanumeric(char c)
{
    if ((c >= 'A' && c <= 'Z')
        || (c >= 'a' && c <= 'z')
        || (c >= '0' && c <= '9')) {
        return 1;
    }
    return 0;
}

int nbr_words(char const *str)
{
    int word_seen = 0;
    int word_count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_alphanumeric(str[i])) {
            word_seen = 0;
        }
        if (is_alphanumeric(str[i]) && !word_seen) {
            word_count++;
            word_seen = 1;
        }
    }
    return word_count + 1;
}

int word_index(char const *str, int word_index)
{
    int j = 0;
    int word;
    int word_seen = 0;
    int word_count = 0;

    while (str[j] != '\0') {
        if (!is_alphanumeric(str[j])) {
            word_seen = 0;
        }
        if (is_alphanumeric(str[j]) && !word_seen &&
            (word_count != word_index)) {
            word_count++;
            word_seen = 1;
            word = j;
        }
        j++;
    }
    return word;
}

int letter_count(char const *str, int word_index)
{
    int letter = 0;

    for (int j = word_index; is_alphanumeric(str[j]) == 1 && str[j] != '\0';
        j++) {
        letter++;
    }
    return letter;
}

char **my_str_to_word_array(char const *str)
{
    int word_count = nbr_words(str);
    char **word_array = malloc(sizeof(char *) * (word_count + 1));
    int word_i;
    int word_len;
    char *new_str = NULL;

    for (int i = 0; i < word_count; i++) {
        word_i = word_index(str, i + 1);
        word_len = letter_count(str, word_i);
        new_str = malloc(sizeof(char) * (word_len + 1));
        my_strncpy(new_str, str + word_i, word_len);
        new_str[word_len] = '\0';
        word_array[i] = new_str;
    }
    free(new_str);
    word_array[word_count - 1] = NULL;
    return word_array;
}
