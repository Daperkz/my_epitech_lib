/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_find_prime_sup
** returns the smallest prime number that is greater than, or equal to,
** the number given as a parameter.
*/

#include "dkz/math.h"

int my_find_prime_sup(int nb)
{
    int i = nb;

    while (!my_is_prime(i))
        i++;
    return i;
}
