/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_isneg
** displays either N if the integer passed as parameter
** is negative or P, if positive or null.
*/

int my_isneg(double n)
{
    return ((n < 0 ? 1 : 0));
}
