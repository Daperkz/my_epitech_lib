/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** my_strrchr
*/

#include <unistd.h>

// returns last occurence of the target char
char *my_strrchr(char const *str, char target)
{
    char const *last = NULL;

    do {
        if (*str == target) {
            last = str;
        }
        str++;
    } while (*str);
    return (char *)(last);
}
