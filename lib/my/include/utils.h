/*
** EPITECH PROJECT, 2025
** utils.h
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_

    #define UNUSED(arg) ((void)arg)

    #define base2 "01"
    #define base7 "01234567"
    #define base10 "0123456789"
    #define base15 "0123456789ABCDEF"

void my_swap(int *a, int *b);
void my_sort_int_array(int *tab, int size);
char *concat_params(int argc, char **argv);
char *convert_base(char const *nbr, char const *base_from, char const *base_to);

char *my_itoab(int nb, char *base);
char *my_uitoab(unsigned int nb, char *base);
char *my_ltoab(long nb, char *base);
char *my_ftoa(double nb, int precision);

#endif /* !UTILS_H_ */
