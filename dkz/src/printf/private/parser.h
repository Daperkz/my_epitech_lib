/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** parser
*/

#ifndef DKZ_PRINTF_PARSER_H_
    #define DKZ_PRINTF_PARSER_H_

    #include "internal.h"

int handle_conversion(
    pf_ctx_t *ctx, const char *format, va_list args, char **str_ptr
);

#endif /* !DKZ_PRINTF_PARSER_H_ */
