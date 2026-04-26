/*
** EPITECH PROJECT, 2026
** my_memmove.c
** File description:
** my_memmove
*/

void *my_memmove(void *dest, const void *src, long n)
{
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    if (d < s) {
        for (long i = 0; i < n; i++)
            d[i] = s[i];
    }
    if (d > s) {
        for (long i = n; i > 0; i--)
            d[i - 1] = s[i - 1];
    }
    return (dest);
}
