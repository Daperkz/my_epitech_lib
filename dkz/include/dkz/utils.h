/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** utils.h
*/
/**
** @file utils.h
** @brief General utility functions and base conversion tools.
**
** This file contains helper functions for sorting, swapping, and
** advanced base conversion for various numeric types.
**
** @author Daperkz
** @ingroup libdkz
** @test ./tests/utils/
** @version 1.0
** @date 2026-07-05
*/

#ifndef DKZ_UTILS_H_
    #define DKZ_UTILS_H_

    #define UNUSED(arg) ((void)arg)

    #define BASE2 "01"
    #define BASE7 "0123456"
    #define BASE8 "01234567"
    #define BASE10 "0123456789"
    #define BASE15CAP "0123456789ABCDEF"
    #define BASE15LOW "0123456789abcdef"

/**
** @brief Swaps the values of two integers
**
** @param[in, out] a Pointer to the first integer
** @param[in, out] b Pointer to the second integer
*/
void my_swap(int *a, int *b);

/**
** @brief Sorts an integer array in ascending order
**
** @param[in, out] tab The array of integers to sort
** @param[in] size The number of elements in the array
*/
void my_sort_int_array(int *tab, int size);

/**
** @brief Concatenates all command-line arguments into a single string
**
** @param[in] argc The number of arguments
** @param[in] argv The array of argument strings
**
** @return @b char* A new allocated string containing all params separated
** by newlines, or NULL on failure
*/
char *concat_params(int argc, char **argv);

/**
** @brief Converts a number string from one base to another
**
** @param[in] nbr The string representation of the number
** @param[in] base_from The current base of @p nbr
** @param[in] base_to The target base for conversion
**
** @return @b char* A new allocated string representing the number
** in @p base_to, or NULL on failure
*/
char *convert_base(char const *nbr, char const *base_from, char const *base_to);

/**
** @brief Converts an integer to a string in a specific base
**
** @param[in] nb The integer to convert
** @param[in] base The base characters (e.g., "0123456789")
**
** @return @b char* A new allocated string, or NULL on failure
*/
char *my_itoab(int nb, char const *base);

/**
** @brief Converts an unsigned integer to a string in a specific base
**
** @param[in] nb The unsigned integer to convert
** @param[in] base The base characters
**
** @return @b char* A new allocated string, or NULL on failure
*/
char *my_uitoab(unsigned int nb, char const *base);

/**
** @brief Converts a long to a string in a specific base
**
** @param[in] nb The long integer to convert
** @param[in] base The base characters
**
** @return @b char* A new allocated string, or NULL on failure
*/
char *my_ltoab(long nb, char const *base);

/**
** @brief Converts a double to a string with specified precision
**
** @param[in] nb The double to convert
** @param[in] precision Number of decimal places to include
**
** @return @b char* A new allocated string, or NULL on failure
*/
char *my_ftoa(double nb, int precision);

#endif /* !DKZ_UTILS_H_ */
