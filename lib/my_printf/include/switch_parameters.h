/*
** EPITECH PROJECT, 2025
** switch_parameters
** File description:
** all the switch functions
*/

#ifndef SWITCH_PARAM_H
    #define SWITCH_PARAM_H
    #include <stdarg.h>
    #include "count_error.h"

int format_gestion(
    int fd, va_list args, const char *format, cot_err_t *coterr
);

#endif
