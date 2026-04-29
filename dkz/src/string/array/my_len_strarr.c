/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_len_strarr
** calculates the number of words the array has
*/

long my_len_strarr(char *const *strarr)
{
    char *const *start;

    if (!strarr)
        return (0);
    start = strarr;
    while (*strarr)
        strarr++;
    return (strarr - start);
}
