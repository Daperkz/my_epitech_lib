/*
** EPITECH PROJECT, 2025
** my_strncpy
** File description:
** copies n characters from a string into another.
** The destination string will already have enough memory
** to contain n characters.
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    char *origin = dest;
    int i = 0;

    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    i = n;
    return origin;
}
