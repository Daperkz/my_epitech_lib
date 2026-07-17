/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** printf.h
*/
/**
** @file printf.h
** @brief Custom implementation of the printf family functions.
**
** Provides formatted output capabilities for standard output,
** file descriptors, and dynamic string allocation.
**
** @author Daperkz
** @ingroup libdkz
** @test ./test/src/printf/
** @version 1.0
** @date 2026-07-05
*/

#ifndef DKZ_PRINTF_H
    #define DKZ_PRINTF_H

    /**
    ** @brief The Standard Input file descriptor
    **/
    #define STDIN_FD 0

    /**
    ** @brief The Standard Output file descriptor
    **/
    #define STDOUT_FD 1

    /**
    ** @brief The Standard Error file descriptor
    **/
    #define STDERR_FD 2

/**
** @brief Produces output according to a format string to the standard output
**
** @param[in] format The format string containing directives
** @param[in] ... Variadic arguments corresponding to the format directives
**
** @return @b int The total number of characters printed, or -1 on failure
**
** @note Supports standard specifiers (e.g., %s, %d, %c, %x, %p).
*/
int my_printf(char const *format, ...);

/**
** @brief Produces output according to a format string to a file descriptor
**
** @param[in] fd The file descriptor where the output will be written
** @param[in] format The format string containing directives
** @param[in] ... Variadic arguments corresponding to the format directives
**
** @return @b int The total number of characters printed, or -1 on failure
*/
int my_fprintf(int fd, char const *format, ...);

/**
** @brief Produces output to an allocated string according to a format string
**
** @param[out] str_ptr Pointer to a char* that will be allocated to hold the
** result
** @param[in] format The format string containing directives
** @param[in] ... Variadic arguments corresponding to the format directives
**
** @return @b int The number of characters "printed" into the string, or -1
** on error
**
** @warning The caller is responsible for freeing the memory allocated
** to @p *str_ptr.
*/
int my_sprintf(char **str_ptr, char const *format, ...);

#endif /* !DKZ_PRINTF_H_ */
