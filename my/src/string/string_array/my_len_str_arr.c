/*
** EPITECH PROJECT, 2025
** my_len_str_arr.c
** File description:
** calculates the number of words the array has
*/

long my_len_str_arr(char **str_arr)
{
    long len = 0;

    if (!str_arr)
        return (0);
    while (*str_arr) {
        len++;
        str_arr++;
    }
    return (len);
}
