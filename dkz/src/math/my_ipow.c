/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_pow
*/

int my_ipow(int n, int p)
{
    int result = 1;

    for (int i = 0; i < p; i++)
        result *= n;
    return result;
}
