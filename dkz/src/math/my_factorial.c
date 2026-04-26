/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_factorial
*/

long my_factorial(int n)
{
    long result = 1;

    for (int i = 1; i < n + 1; i++)
        result *= i;
    return result;
}
