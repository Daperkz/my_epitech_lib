/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_ipow
*/

long long my_ipow(int n, int p)
{
    long long result = 1;

    for (int i = 0; i < p; i++)
        result *= n;
    return result;
}
