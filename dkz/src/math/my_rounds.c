/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_rounds
*/

double my_ceil(double x)
{
    int i = (long long)x;

    if (x > 0 && x != i)
        i++;
    return i;
}

double my_floor(double x)
{
    int i = (long long)x;

    if (x < 0 && x != i)
        i--;
    return i;
}

double my_round(double x)
{
    if (x < 0)
        return my_ceil(x - 0.5);
    else
        return my_floor(x + 0.5);
}

double my_trunc(double x)
{
    return (long long)x;
}
