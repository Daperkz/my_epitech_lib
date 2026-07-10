/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** printf
*/

#include <unistd.h>

#include "dkz.h"
#include "private_dkz.h"


static int no_format_case(int fd, char const **format, pf_ctx_t *ctx)
{
    int offset = my_strlen_d(*format, '%');
    int formatlen = my_strlen(*format);

    if (offset == formatlen) {
        ctx->error = my_fputnstr(fd, *format, formatlen) == -1 ?
            1 : ctx->error;
        ctx->count += formatlen;
        return (EXIT_FAILURE);
    }
    ctx->error = (my_fputnstr(fd, *format, offset) == -1) ? 1 : ctx->error;
    ctx->count += offset;
    (*format) += offset;
    return (EXIT_DONE);
}

static int internal_printf(int fd, char const *format, va_list args)
{
    pf_ctx_t ctx = {fd, 0, 0};
    int offset;
    int retv = EXIT_SUCCESS;

    while (*format) {
        retv = EXIT_SUCCESS;
        if (*format != '%')
            retv = no_format_case(fd, &format, &ctx);
        if (retv == EXIT_FAILURE)
            break;
        if (retv == EXIT_DONE)
            continue;
        offset = handle_conversion(&ctx, format + 1, args, NULL);
        if (offset <= 0)
            return (-1);
        format += (offset + 1);
    }
    return ctx.error ? -1 : ctx.count;
}

int my_printf(char const *format, ...)
{
    va_list args;
    int ret;

    if (!format)
        return (-1);
    va_start(args, format);
    ret = internal_printf(1, format, args);
    va_end(args);
    return ret;
}

int my_fprintf(int fd, char const *format, ...)
{
    va_list args;
    int ret;

    if (!format)
        return (-1);
    va_start(args, format);
    ret = internal_printf(fd, format, args);
    va_end(args);
    return ret;
}

static int isnotspecifier(char **str_ptr, pf_ctx_t *ctx, char const **format)
{
    char tmp[2] = {*(*format), 0};

    if (*(*format) != '%') {
        if (!my_strappend(str_ptr, tmp))
            return (-1);
        (ctx->count)++;
        (*format)++;
        return (EXIT_SUCCESS);
    }
    return (EXIT_FAILURE);
}

static int internal_sprintf(char **str_ptr, char const *format, va_list args)
{
    pf_ctx_t ctx = {-1, 0, 0};
    int offset = 0;
    int retv;

    while (*format) {
        retv = isnotspecifier(str_ptr, &ctx, &format);
        if (retv == -1)
            return (retv);
        if (retv == EXIT_SUCCESS)
            continue;
        offset = handle_conversion(&ctx, format + 1, args, str_ptr);
        if (offset <= 0)
            return (-1);
        format += (offset + 1);
    }
    return (ctx.count);
}

int my_sprintf(char **str_ptr, char const *format, ...)
{
    va_list args;
    int ret;
    short allocated_here = 0;

    if (!str_ptr)
        return (-1);
    if (!(*str_ptr)) {
        *str_ptr = my_strdup("");
        if (!*str_ptr)
            return (-1);
        allocated_here = 1;
    }
    va_start(args, format);
    ret = internal_sprintf(str_ptr, format, args);
    va_end(args);
    if (ret == -1 && allocated_here) {
        free(*str_ptr);
        *str_ptr = NULL;
    }
    return ret;
}
