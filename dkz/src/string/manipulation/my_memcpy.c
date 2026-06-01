/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** my_memcpy
*/

void *my_memcpy(void *dest, void const *src, long n)
{
    char *d = (char *)dest;
    const char *s = (const char *)src;

    for (long i = 0; i < n; i++)
        d[i] = s[i];
    return (dest);
}
