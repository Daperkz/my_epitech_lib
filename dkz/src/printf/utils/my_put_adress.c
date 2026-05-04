/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_put_adress
** prints out a float in hex
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "dkz/string.h"
#include "dkz/utils.h"

char *my_put_adress(void *a)
{
    unsigned long addr = (unsigned long) a;
    char *str = NULL;
    char *nbr = NULL;

    if (a == NULL) {
        return my_strdup("(nil)");
    }
    nbr = my_ltoab(addr, "0123456789abcdef");
    str = nbr ? malloc(sizeof(char) * (2 + my_strlen(nbr) + 1)) : NULL;
    if (!str) {
        free(nbr);
        return NULL;
    }
    my_strcpy(str, "0x");
    my_strcat(str, nbr);
    free(nbr);
    return str;
}
