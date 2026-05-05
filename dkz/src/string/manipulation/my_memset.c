/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** my_memset
*/

void *my_memset(void *dest, int c, long n)
{
    unsigned char *d = dest;

    while (n > 0) {
        *d = (unsigned char)c;
        d++;
        n--;
    }
    return (d);
}
