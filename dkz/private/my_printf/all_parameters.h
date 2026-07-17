/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** all_parameters
*/
/**
** @file all_parameters.h
** @brief Specific conversion handlers for the my_printf dispatch table.
**
** @internal
** This header declares the individual parameter conversion callbacks mapped to
** each supported format specifier (e.g., %d, %s, %f) in the my_printf engine.
**
** @author Daperkz
** @ingroup libdkz
** @test ./test/src/printf/parameters/
** @version 1.0
** @date 2026-07-17
*/

#ifndef DKZ_PRINTF_ALL_PARAMETERS_H_
    #define DKZ_PRINTF_ALL_PARAMETERS_H_

    #include <stdarg.h>
    #include <unistd.h>

    #include "internal.h"

/*
** -_-
** PARAMETER HANDLERS
** -_-
*/

/**
** @brief Converts signed decimal integers (%d, %i)
** @internal
**/
char *parameter_d(va_list args, pf_ctx_t *coterr);

/**
** @brief Converts unsigned decimal integers (%u)
** @internal
**/
char *parameter_u(va_list args, pf_ctx_t *coterr);

/**
** @brief Converts unsigned octal values (%o)
** @internal
**/
char *parameter_o(va_list args, pf_ctx_t *coterr);

/**
** @brief Converts unsigned hexadecimal values using lowercase letters (%x)
** @internal
**/
char *parameter_x(va_list args, pf_ctx_t *coterr);

/**
** @brief Converts unsigned hexadecimal values using uppercase letters (%X)
** @internal
**/
char *parameter_xx(va_list args, pf_ctx_t *coterr);

/**
** @brief Converts double values to decimal notation with lowercase infinity/nan (%f)
** @internal
**/
char *parameter_f(va_list args, pf_ctx_t *coterr);

/**
** @brief Converts double values to decimal notation with uppercase infinity/nan (%F)
** @internal
**/
char *parameter_ff(va_list args, pf_ctx_t *coterr);

/**
** @brief Converts double values to scientific notation with lowercase 'e' (%e)
** @internal
**/
char *parameter_e(va_list args, pf_ctx_t *coterr);

/**
** @brief Converts double values to scientific notation with uppercase 'E' (%E)
** @internal
**/
char *parameter_ee(va_list args, pf_ctx_t *coterr);

/**
** @brief Converts double values to general notation using shorter variant (%g)
** @internal
**/
char *parameter_g(va_list args, pf_ctx_t *coterr);

/**
** @brief Converts double values to general notation using shorter variant with uppercase 'E' (%G)
** @internal
**/
char *parameter_gg(va_list args, pf_ctx_t *coterr);

/**
** @brief Converts double values to hexadecimal scientific notation with lowercase prefix (%a)
** @internal
**/
char *parameter_a(va_list args, pf_ctx_t *coterr);

/**
** @brief Converts double values to hexadecimal scientific notation with uppercase prefix (%A)
** @internal
**/
char *parameter_aa(va_list args, pf_ctx_t *coterr);

/**
** @brief Converts characters (%c)
** @internal
**/
char *parameter_c(va_list args, pf_ctx_t *coterr);

/**
** @brief Converts null-terminated strings (%s)
** @internal
**/
char *parameter_s(va_list args, pf_ctx_t *coterr);

/**
** @brief Converts memory addresses to hexadecimal strings prefixed with 0x (%p)
** @internal
**/
char *parameter_p(va_list args, pf_ctx_t *coterr);

/**
** @brief Stores the count of successfully written characters into the int pointer argument (%n)
**
** @internal
** Unlike other handlers, this does not return a formatted value. Instead, it
** writes `coterr->count` directly to the referenced memory buffer.
**/
char *parameter_n(va_list args, pf_ctx_t *coterr);

/**
** @brief Renders a literal percentage character (%%)
** @internal
**/
char *parameter_percent(va_list args, pf_ctx_t *coterr);

/**
** @brief Generates an error representation fallback when parsing a corrupted specifier sequence
** @internal
**/
char *error_output(char error_char, pf_ctx_t *coterr);

/*
** -_-
** DISPATCH MAPS
** -_-
*/

/**
** @brief The global dispatch table mapping specifier characters to their handlers
** @internal
**/
extern const flag_map_t ALL_FORMAT[];

#endif /* !DKZ_PRINTF_ALL_PARAMETERS_H_ */
