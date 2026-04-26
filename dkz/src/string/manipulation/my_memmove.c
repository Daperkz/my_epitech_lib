/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** my_memmove
*/

void *my_memmove(void *dest, void const *src, long n)
{
    unsigned char *d = (unsigned char *)dest;
    unsigned char const *s = (unsigned char const *)src;

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
