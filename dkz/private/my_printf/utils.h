/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** includes small my_lib features
*/

#ifndef DKZ_PRINTF_UTILS_H_
    #define DKZ_PRINTF_UTILS_H_

    #include <stdlib.h>

char *my_put_float_hex(double nb, char *base);
char *my_put_scientific(double nb, char *base, int cap);
char *my_put_adress(void *a);

#endif
