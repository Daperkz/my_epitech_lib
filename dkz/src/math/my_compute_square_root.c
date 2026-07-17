/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int result = 0;

    if (nb < 0)
        return 0;
    for (int i = 1; nb > 0; i += 2) {
        nb -= i;
        result++;
    }
    if (nb != 0)
        return 0;
    return result;
}
