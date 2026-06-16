/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** io.h
*/
/**
** @file io.h
** @brief Basic Input/Output functions.
**
** Includes functions for printing characters, numbers, and
** debugging tools like memory and string hex-dumps.
**
** @author Daperkz
** @ingroup libdkz
** @test ./tests/io/
** @version 1.0
** @date 2026-07-05
*/

#ifndef DKZ_IO_H_
    #define DKZ_IO_H_

/**
** @brief Prints a single character to the standard output
**
** @param[in] c The character to print
**
** @return @b int The number of characters printed (1), or -1 on error /
** Syscall error
*/
int my_putchar(char c);

/**
** @brief Prints a single character to the file descriptor
**
** @param[in] fd The file descriptor (e.g., 1 for stdout, 2 for stderr)
** @param[in] c The character to print
**
** @return @b int The number of characters printed (1), or -1 on error /
** Syscall error
*/
int my_putchar_fd(int fd, char c);

/**
** @brief Prints an integer to the standard output
**
** @param[in] nb The integer to print
**
** @return @b int The number of digits/characters printed
*/
int my_put_nbr(int nb);

/**
** @brief Prints an integer in a specific base to the standard output
**
** @param[in] nb The integer to print
** @param[in] base A string representing the base (e.g., "0123456789ABCDEF")
**
** @return @b int The number of characters printed
*/
int my_put_nbr_base(int nb, char const *base);

/**
** @brief Prints a double to the standard output
**
** @param[in] nb The double to print
** @param[in] precision The amount of decimals printed out
**
** @return @b int The number of characters printed
*/
int my_put_float(double nb, int precision);

/**
** @brief Prints a string, representing non-printable characters as hex
**
** @param[in] str The string to display
**
** @return @b int The number of characters printed
*/
int my_showstr(char const *str);

/**
** @brief Displays a memory area in hexadecimal format
**
** @param[in] str The pointer to the memory area
** @param[in] size The number of bytes to display
**
** @return @b int 0 on success
*/
int my_showmem(char const *str, int size);

/**
** @brief Displays the content of a NULL-terminated array of strings
**
** @param[in] tab The string array to display
**
** @return @b int The number of characters printed
*/
int my_show_word_array(char **tab);

#endif /* !DKZ_IO_H_ */
