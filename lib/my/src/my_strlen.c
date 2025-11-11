/*
** EPITECH PROJECT, 2025
** my_strlen
** File description:
** counts and returns the number of characters found in the string
** passed as parameter
*/

int my_strlen(char const *str)
{
    const char *start = str;

    while (*str) {
        str++;
    }
    return str - start;
}
