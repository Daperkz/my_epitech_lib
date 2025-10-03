/*
** EPITECH PROJECT, 2025
** my_isneg
** File description:
** displays either N if the integer passed as parameter
** is negative or P, if positive or null.
*/

#include "tools.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return 0;
}
