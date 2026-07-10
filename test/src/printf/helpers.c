/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** helpers
*/

#include "test.h"

static int dummy_trigger_parser_force_stack(
    pf_ctx_t *ctx, const char *format, char **str_ptr,
    long d1, long d2, long d3, long d4,
    long d5, long d6, long d7, long d8, ...)
{
    va_list args;

    UNUSED(d1);
    UNUSED(d2);
    UNUSED(d3);
    UNUSED(d4);
    UNUSED(d5);
    UNUSED(d6);
    UNUSED(d7);
    va_start(args, d8);
    int res = handle_conversion(ctx, format, args, str_ptr);
    va_end(args);
    return res;
}

static int dummy_trigger_parser(
    pf_ctx_t *ctx, const char *format, char **str_ptr, ...)
{
    va_list args;

    va_start(args, str_ptr);
    int res = handle_conversion(ctx, format, args, str_ptr);
    va_end(args);
    return res;
}

int handle_conversion_wrapper(
    pf_ctx_t *ctx, const char *format, char **str_ptr, struct hcv_args_s *args
)
{
    if (!args)
        return dummy_trigger_parser(ctx, format, str_ptr);
    return dummy_trigger_parser(
        ctx, format, str_ptr, args->width, args->precision
    );
}

int handle_conversion_wrapper_force_stack(
    pf_ctx_t *ctx, const char *format, char **str_ptr, struct hcv_args_s *args
)
{
    if (!args)
        return dummy_trigger_parser_force_stack(
            ctx, format, str_ptr, 1, 2, 3, 4, 5, 6, 7, 8
        );
    return dummy_trigger_parser_force_stack(
        ctx, format, str_ptr,
        1, 2, 3, 4, 5, 6, 7, 8, args->width, args->precision
    );
}
