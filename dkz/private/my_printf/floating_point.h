/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** floating_point
*/
/**
** @file floating_point.h
** @brief Binary deconstruction tools for floating-point calculations.
**
** @internal
** This file contains bitwise-level overlay structures for doubles, enabling
** the my_printf engine to directly parse the sign bit, exponent, and mantissa
** for custom precision and rendering algorithms.
**
** @author Daperkz
** @ingroup libdkz
** @test ./test/src/printf/
** @version 1.0
** @date 2026-07-17
*/

#ifndef DKZ_PRINTF_DECONSTRUCT_FLOAT_H_
    #define DKZ_PRINTF_DECONSTRUCT_FLOAT_H_

/*
** -_-
** FLOATING POINT DECONSTRUCTION
** -_-
*/

/**
** @brief Union overlay for double-precision float bit manipulation.
**
** @internal
** Maps the raw IEEE-754 double representation onto an unsigned 64-bit integer.
** This structure allows direct bit-shifting to extract:
** - Sign bit (1 bit)
** - Biased Exponent (11 bits)
** - Mantissa/Fraction (52 bits)
**/
typedef union {
    double f;
    unsigned long long bits;
} double_t;

#endif /* !DKZ_PRINTF_DECONSTRUCT_FLOAT_H_ */
