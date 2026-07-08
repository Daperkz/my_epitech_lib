/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** helpers
*/

#include "test.h"

char *parameter_wrapper(
    pf_ctx_t *c, char *(*parameter_func)(va_list, pf_ctx_t *), ...
)
{
    char *result;
    va_list args;

    va_start(args, parameter_func);
    result = parameter_func(args, c);
    va_end(args);
    return result;
}

static char *dummy_trigger_int(
    pf_ctx_t *ctx, char *(*func)(va_list, pf_ctx_t *),
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
    char *res = func(args, ctx);
    va_end(args);
    return res;
}

static char *dummy_trigger_string(
    pf_ctx_t *ctx, char *(*func)(va_list, pf_ctx_t *),
    char *d1, char *d2, char *d3, char *d4,
    char *d5, char *d6, char *d7, char *d8, ...)
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
    char *res = func(args, ctx);
    va_end(args);
    return res;
}

static char *dummy_trigger_float(
    pf_ctx_t *ctx, char *(*func)(va_list, pf_ctx_t *),
    double d1, double d2, double d3, double d4,
    double d5, double d6, double d7, double d8, ...)
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
    char *res = func(args, ctx);
    va_end(args);
    return res;
}

static char *dummy_trigger_ptr(
    pf_ctx_t *ctx, char *(*func)(va_list, pf_ctx_t *),
    void *d1, void *d2, void *d3, void *d4,
    void *d5, void *d6, void *d7, void *d8, ...)
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
    char *res = func(args, ctx);
    va_end(args);
    return res;
}

char *parameter_wrapper_stack_forced(
    pf_ctx_t *c, char *(*parameter_func)(va_list, pf_ctx_t *),
    const char *type, void *val
)
{
    if (strcmp(type, "int") == 0) {
        return dummy_trigger_int(c, parameter_func,
            1, 2, 3, 4, 5, 6, 7, 8, *(long *)val);
    }
    if (strcmp(type, "string") == 0) {
        return dummy_trigger_string(c, parameter_func,
            "1", "2", "3", "4", "5", "6", "7", "8", (char *)val);
    }
    if (strcmp(type, "ptr") == 0) {
        return dummy_trigger_ptr(c, parameter_func,
            (void *)1, (void *)2, (void *)3, (void *)4, (void *)5, (void *)6,
            (void *)7, (void *)8, (void *)val);
    }
    if (strcmp(type, "float") == 0) {
        return dummy_trigger_float(c, parameter_func,
            1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, *(double *)val);
    }
    return NULL;
}
