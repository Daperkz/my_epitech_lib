/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** my_strsep
*/

#include <unistd.h>

static int issep(char c, const char *sep)
{
    while (*sep) {
        if (c == *sep)
            return 1;
        sep++;
    }
    return 0;
}

char *my_strsep(char **str_p, const char *sep)
{
    char *str = NULL;
    char *start = NULL;

    if (!str_p || !(*str_p) || !sep)
        return (NULL);
    str = (*str_p);
    start = str;
    while (*str) {
        if (issep(*str, sep)) {
            *str = '\0';
            (*str_p) = str + 1;
            return (start);
        }
        str++;
    }
    *str_p = NULL;
    return start;
}
