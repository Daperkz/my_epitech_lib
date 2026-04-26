/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** floating_point
** union containing a float which is splitted into 3 parts from the bits the
** 1bit sign - or +, exponent the integer value of the float number + the 52bits
** of the mantissa which corresponds to the float
*/

#ifndef DKZ_PRINTF_DECONSTRUCT_FLOAT_H_
    #define DKZ_PRINTF_DECONSTRUCT_FLOAT_H_

typedef union {
    double f;
    unsigned long long bits;
} double_t;

#endif
