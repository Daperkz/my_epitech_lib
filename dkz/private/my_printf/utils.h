/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** includes small my_lib features
*/
/**
** @file utils.h
** @brief Private utility helper functions for the my_printf engine.
**
** @internal
** This header contains low-level formatting tools used internally by
** the my_printf engine. It should not be exposed in public-facing builds.
**
** @author Daperkz
** @ingroup libdkz
** @test ./test/src/printf/utils/
** @version 1.0
** @date 2026-07-17
*/

#ifndef DKZ_PRINTF_UTILS_H_
    #define DKZ_PRINTF_UTILS_H_

    #include <stdlib.h>

/*
** -_-
** INTERNAL FORMATTING UTILS
** -_-
*/

/**
** @brief Converts a double-precision float to its hexadecimal representation
**
** @internal
** Converts the floating-point value to its hexadecimal scientific notation
** (corresponding to the %a / %A format specifiers in standard printf).
**
** @param[in] nb The double-precision floating-point number to convert.
** @param[in] base The base characters used for the conversion
** (e.g. "0123456789abcdef").
**
** @return @b char* A newly allocated, NULL-terminated string containing the
** hexadecimal float representation, or NULL on memory allocation failure.
**/
char *my_put_float_hex(double nb, char *base);

/**
** @brief Formats a double-precision float into scientific notation
**
** @internal
** Converts a double value into scientific notation
** (e.g., 1.23e+04 or 1.23E+04).
**
** @param[in] nb The double-precision floating-point number to convert.
** @param[in] base The base characters used for the mantissa
** (e.g. "0123456789").
** @param[in] cap A boolean-like flag (0 or 1) representing whether to use
** capital 'E' (1) or lowercase 'e' (0) for the exponent.
**
** @return @b char* A newly allocated, NULL-terminated string containing the
** scientific representation, or NULL on memory allocation failure.
**/
char *my_put_scientific(double nb, char *base, int cap);

/**
** @brief Formats a raw memory pointer address into a hex string
**
** @internal
** Converts a generic void pointer address into a standardized hex string
** representation prefixed with "0x" (corresponding to the %p format specifier).
**
** @param[in] a The generic memory pointer to format.
**
** @return @b char* A newly allocated, NULL-terminated string containing the
** formatted address (e.g., "0x7ffeefbff5c8"), or "nil" / "0x0" if @p a is NULL.
** Returns NULL on memory allocation failure.
**/
char *my_put_adress(void *a);

#endif /* !DKZ_PRINTF_UTILS_H_ */
