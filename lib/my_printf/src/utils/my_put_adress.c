/*
** EPITECH PROJECT, 2025
** mu_put_float_hex_capitalize
** File description:
** prints out a float in hex
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_strcat.h"
#include "my_putnbr.h"

char *my_put_adress(void *a)
{
    unsigned long addr = (unsigned long) a;
    char *str = malloc(sizeof(char) * 1);

    str[0] = '\0';
    if (a == NULL) {
        return my_strcat(str, "(nil)");
    }
    my_strcat(str, "0x");
    my_strcat(str, my_put_long_base(addr, "0123456789abcdef"));
    return str;
}
