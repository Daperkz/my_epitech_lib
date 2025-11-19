/*
** EPITECH PROJECT, 2025
** my_strlen
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    const char *start = str;

    if (!str) {
        return -1;
    }
    while (*str) {
        str++;
    }
    return str - start;
}
