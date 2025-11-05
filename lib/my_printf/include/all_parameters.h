/*
** EPITECH PROJECT, 2025
** all_parameters
** File description:
** all_parameters
*/

#ifndef ALL_PARAMETERS_H_
    #define ALL_PARAMETERS_H_

    #include <stdarg.h>
    #include "flag_to_func.h"
    #include "modifiers.h"
    #include "count_error.h"

void parameter_d(int fd, va_list args, cot_err_t *coterr);
void parameter_u(int fd, va_list args, cot_err_t *coterr);
void parameter_o(int fd, va_list args, cot_err_t *coterr);
void parameter_x(int fd, va_list args, cot_err_t *coterr);
void parameter_xx(int fd, va_list args, cot_err_t *coterr);
void parameter_f(int fd, va_list args, cot_err_t *coterr);
void parameter_ff(int fd, va_list args, cot_err_t *coterr);
void parameter_e(int fd, va_list args, cot_err_t *coterr);
void parameter_ee(int fd, va_list args, cot_err_t *coterr);
void parameter_g(int fd, va_list args, cot_err_t *coterr);
void parameter_gg(int fd, va_list args, cot_err_t *coterr);
void parameter_a(int fd, va_list args, cot_err_t *coterr);
void parameter_aa(int fd, va_list args, cot_err_t *coterr);
void parameter_c(int fd, va_list args, cot_err_t *coterr);
void parameter_s(int fd, va_list args, cot_err_t *coterr);
void parameter_p(int fd, va_list args, cot_err_t *coterr);
void parameter_n(int fd, va_list args, cot_err_t *coterr);
void parameter_percent(int fd, va_list args, cot_err_t *coterr);
void error_output(char error_char, cot_err_t *coterr);

#endif
