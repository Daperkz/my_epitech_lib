/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** my_printf_internal
*/
/**
** @file my_printf_internal.h
** @brief Core internal structures, types, and engine definitions for my_printf.
**
** @internal
** This file provides the structural backbone of the custom my_printf engine,
** defining context states, format parsing specifications, and formatting
** function pointer maps.
**
** @author Daperkz
** @ingroup libdkz
** @test ./test/src/printf/
** @version 1.0
** @date 2026-07-17
*/

#ifndef DKZ_PRINTF_INTERNAL_H_
    #define DKZ_PRINTF_INTERNAL_H_

    #include <stdarg.h>

    #include "utils.h"

/*
** -_-
** STRUCTURES
** -_-
*/

/**
** @brief Active printing context track-state.
**
** @internal
** Stores tracking metrics across the printing lifecycle, including the output
** destination file descriptor, the ongoing character write count, and standard
** output/error flags.
**/
typedef struct printf_ctx_s {
    int fd;      /**< Target file descriptor for write operations. */
    int count;   /**< Total number of successfully printed characters. */
    int error;   /**< Error tracking state; non-zero if a syscall fails. */
} pf_ctx_t;

/**
** @brief Formatting modifiers and specifiers parsed from the format string.
**
** @internal
** Holds width, precision, flag states ('#', '-', '+', ' ', '0'), and sub-type
** length modifiers (e.g., 'h', 'l', 'z') corresponding to a single specifier.
**/
typedef struct printf_info_s {
    int width;
    int precision;
    int sharp;
    int left;
    int plus;
    int space;
    int zero;
    char length;
} pf_info_t;

/*
** -_-
** TYPEDEFS & DISPATCH TABLE MAPS
** -_-
*/

/**
** @brief Function pointer definition for individual format specifier handlers.
**
** @internal
** Each concrete conversion function
** (e.g. for converting integers, strings, etc.)
** must match this signature, retrieving variables from the arguments list and
** writing/interacting with the standard printing context.
**
** @param[in, out] args The argument list pointer containing
** parameters to convert.
** @param[in, out] ctx The active engine printing state context.
**
** @return @b char* An allocated, NULL-terminated formatting string output,
** or NULL if formatting fails or memory allocation errors occur.
**/
typedef char *(*flag_func_t)(va_list, pf_ctx_t *);

/**
** @brief Structure representing a key-value specifier-to-handler map.
**
** @internal
** Links a single format flag specifier character (e.g., 'd', 's', 'x')
** to its dedicated formatting function pointer helper.
**/
typedef struct flag_map_s {
    char flag;          /**< The specifier trigger character. */
    flag_func_t func;   /**< Dedicated formatting function hook. */
} flag_map_t;

#endif /* !DKZ_PRINTF_INTERNAL_H_ */
