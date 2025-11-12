/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** concatenates two strings into dest must have enough space allocated.
*/

char *my_strcat(char *dest, char const *src)
{
    char *origin = dest;

    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return origin;
}
