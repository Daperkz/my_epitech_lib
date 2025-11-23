/*
** EPITECH PROJECT, 2025
** my_put_nbr
** File description:
** displays the number given as a parameter.
** It must be able to display all the possible values of an int
*/

#include "io_utils.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else {
        my_putchar(nb + '0');
    }
    return 0;
}
