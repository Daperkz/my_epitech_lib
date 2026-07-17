/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** modifiers.h
** modifiers
*/
/**
** @file modifiers.h
** @brief Format modifiers processing helper functions.
**
** @internal
** This header provides functions to manipulate the formatted
** intermediate strings
** by applying the width, precision, and flag configurations parsed from the
** current specifier.
**
** @author Daperkz
** @ingroup libdkz
** @test ./test/src/printf/modifiers/
** @version 1.0
** @date 2026-07-17
*/

#ifndef DKZ_PRINTF_MODIFIER_H_
    #define DKZ_PRINTF_MODIFIER_H_

    #include "internal.h"

/*
** -_-
** MODIFIER PROCESSORS
** -_-
*/

/**
** @brief Adjusts the width of the target string based on format info
**
** @internal
** Pads the string with spaces or zeroes to meet the minimum width constraint
** specified in @p info, respecting left/right alignment.
**
** @param[in] str The formatted intermediate string.
** @param[in] info Pointer to the active parsing configuration structure.
**
** @return @b char* A newly allocated string padded to width,
** or NULL on failure.
**/
char *apply_width(char *str, pf_info_t *info);

/**
** @brief Sets precision modifiers on the parsed value
**
** @internal
** Truncates, rounds, or zero-pads the output string to match the precision
** constraints, varying behavior depending on the specifier family.
**
** @param[in] str The formatted intermediate string.
** @param[in] info Pointer to the active parsing configuration structure.
** @param[in] specifier The active flag specifier character (e.g., 'd', 'f').
**
** @return @b char* A newly allocated string with precision applied, or NULL.
**/
char *apply_precision(char *str, pf_info_t *info, char specifier);

/**
** @brief Prepends sign flags (+ or spaces) to numeric outputs
**
** @internal
** Evaluates numeric format criteria and injects positive/negative prefixes
** into the raw output when '+' or ' ' (space) flags are active.
**
** @param[in] str The formatted intermediate string.
** @param[in] info Pointer to the active parsing configuration structure.
** @param[in] specifier The active flag specifier character (e.g., 'd', 'i').
**
** @return @b char* A newly allocated string with signs applied,
** or NULL on failure.
**/
char *apply_sign_flags(char *str, pf_info_t *info, char specifier);

/**
** @brief Integrates the alternative '#' flag representation
**
** @internal
** Applies the sharp modifier formatting rule (e.g. prepending "0x", "0X", "0"
** or enforcing a decimal point on float conversions).
**
** @param[in] str The formatted intermediate string.
** @param[in] specifier The active flag specifier character.
**
** @return @b char* A newly allocated string with alternative flags,
** or NULL on failure.
**/
char *apply_sharp_flag(char *str, char specifier);

#endif /* !DKZ_PRINTF_MODIFIER_H */
