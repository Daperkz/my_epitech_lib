/*
** EPITECH PROJECT, 2025
** my_strstr
** File description:
** searches for a str in a str
*/

#include "string_utils.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int pat_size = my_strlen(to_find);

    while (str[i] != '\0') {
        if (my_strncmp(&str[i], to_find, pat_size) == 0) {
            return &str[i];
        }
        i++;
    }
    return 0;
}
