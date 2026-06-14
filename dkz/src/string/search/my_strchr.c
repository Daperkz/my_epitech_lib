/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** my_strchr
*/

#include <unistd.h>

// returns first occurence of the target char
char *my_strchr(char const *str, char target)
{
    if (!str)
        return (NULL);
    while (*str) {
        if (*str == target)
            return (char *)(str);
        str++;
    }
    if (*str == target)
        return (char *)(str);
    return (NULL);
}

// returns last occurence of the target char
char *my_strrchr(char const *str, char target)
{
    char const *last = NULL;

    if (!str)
        return (NULL);
    while (*str){
        if (*str == target) {
            last = str;
        }
        str++;
    }
    if (*str == target)
        return (char *)(str);
    return (char *)(last);
}
