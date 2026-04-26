/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_compute_power_rec.c
** returns the first argument raised to the power p,
** where p is the second argument.
*/

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p == 0) {
        return 1;
    }
    if (p > 0) {
        result = nb * my_compute_power_rec(nb, p - 1);
    }
    if (p < 0)
        return 0;
    return result;
}
