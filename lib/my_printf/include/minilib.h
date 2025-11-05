/*
** EPITECH PROJECT, 2025
** minilib
** File description:
** includes small my_lib features
*/

#ifndef MINILIB_H
    #define MINILIB_H

    #include <stdlib.h>
    #include "my_putchar.h"
    #include "my_putnbr.h"
    #include "count_error.h"

char *my_strcat(char *dest, char *src);
char *my_strcpy(char *dest, char const *src);
char *my_put_float(double nb);
char *my_put_float_hex(double nb, char *base);
char *my_put_scientific(double nb, char *base);
char *my_put_scientific_capitalize(double nb, char *base);
char *my_put_adress(void *a);
void my_putstr(int fd, char *str, cot_err_t *coterr);



#endif
