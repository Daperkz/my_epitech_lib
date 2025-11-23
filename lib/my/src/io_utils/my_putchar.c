/*
** EPITECH PROJECT, 2025
** my_putchar
** File description:
** prints out a character
*/

#include "unistd.h"

int my_putchar(char c)
{
    return write(1, &c, 1);
}
