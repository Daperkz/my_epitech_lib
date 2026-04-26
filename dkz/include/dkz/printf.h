/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** printf.h
*/

#ifndef DKZ_PRINTF_H
    #define DKZ_PRINTF_H

    #define STDIN_FD 0
    #define STDOUT_FD 1
    #define STDERR_FD 2

int my_printf(const char *format, ...);

int my_fprintf(int fd, const char *format, ...);

int my_sprintf(char **str_ptr, const char *format, ...);

#endif /* !DKZ_PRINTF_H_ */
