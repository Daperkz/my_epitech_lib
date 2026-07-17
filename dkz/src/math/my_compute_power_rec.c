/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_compute_power_rec
*/

long long my_compute_power_rec(int nb, int p)
{
    long long result;

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
