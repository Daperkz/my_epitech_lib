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
** @test ./test/src/utils/
** @version 1.0
** @date 2026-07-05
*/

#ifndef DKZ_UTILS_H_
    #define DKZ_UTILS_H_

    /**
    ** @brief Macro used to silence unused warnings
    **/
    #define UNUSED(arg) ((void)arg)

    /**
    ** @brief string representing the Base 2
    **/
    #define BASE2 "01"

    /**
    ** @brief string representing the Base 7
    **/
    #define BASE7 "0123456"

    /**
    ** @brief string representing the Base 8
    **/
    #define BASE8 "01234567"

    /**
    ** @brief string representing the Base 10
    **/
    #define BASE10 "0123456789"

    /**
    ** @brief string representing the Base 15 with captial letters
    **/
    #define BASE16CAP "0123456789ABCDEF"

    /**
    ** @brief string representing the Base 15 with lower letters
    **/
    #define BASE16LOW "0123456789abcdef"

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

#endif /* !DKZ_UTILS_H_ */
