/*
** EPITECH PROJECT, 2026
** my_memcpy.c
** File description:
** my_memcpy
*/

void *my_memcpy(void *dest, const void *src, long n)
{
    char *d = (char *)dest;
    const char *s = (const char *)src;

    for (long i = 0; i < n; i++)
        d[i] = s[i];
    return (dest);
}
