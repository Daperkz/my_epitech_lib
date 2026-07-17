/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** math.h
*/
/**
** @file math.h
** @brief Header file for math functions
**
** Provides basic and complex math functions and operations.
**
** Provides basic, rounding, and complex mathematical functions,
** alongside commonly used mathematical constants and macros.
**
** @author Daperkz
** @ingroup libdkz
** @test ./test/src/math/
** @version 1.0
** @date 2026-07-11
*/


#ifndef DKZ_MATH_H_
    #define DKZ_MATH_H_

    /**
    ** @brief Mathematical constant Pi
    ** (ratio of a circle's circumference to its diameter)
    **/
    #define PI 3.14159265359

    /**
    ** @brief Mathematical constant e (Euler's number)
    **/
    #define E 2.71828

    /**
    ** @brief Generates a random floating-point number between 0.0 and 1.0
    **/
    #define RAND_F (rand() / (RAND_MAX + 1.0))

    /**
    ** @brief Calculates the absolute value of x
    **/
    #define ABS(x) ((x) < 0 ? -x : x)

    /**
    ** @brief Returns the sign of x (-1, 0, or 1)
    **/
    #define SIGN(x) my_sign(x)

    /**
    ** @brief Returns the smaller of two values
    **/
    #define MIN(x, y) (x < y ? x : y)

    /**
    ** @brief Returns the larger of two values
    **/
    #define MAX(x, y) (x > y ? x : y)

/*
** -_-
** SIGN & UTILS
** -_-
*/

/**
** @brief Checks for the sign value of a double
**
** @param[in] x The value to check
**
** @return @b int The sign representation of @p x
** @retval -1 If @p x is negative.
** @retval 0 If @p x is equal to 0.
** @retval 1 If @p x is positive.
**/
int my_sign(double x);

/**
** @brief Checks if the double is negative
**
** @param[in] nb The value to check
**
** @return @b int A boolean flag indicating negativity
** @retval 1 If @p nb is strictly negative.
** @retval 0 If @p nb is positive or equal to 0.
**/
int my_isneg(double nb);

/**
** @brief Calculates the number of digits in an integer
**
** @param[in] x The integer to measure
**
** @return @b int The count of digits in @p x
**/
int my_intlen(int x);

/**
** @brief Calculates the length of an integer when represented in a given base
**
** @param[in] x The integer to measure
** @param[in] baselen The length of the target base
**
** @return @b int The count of characters required to
** represent @p x in that base
**/
int my_intlenb(int x, int baselen);


/*
** -_-
** ARITHMETIC
** -_-
*/

/**
** @brief Calculates the power of an integer recursively
**
** @param[in] nb The base number
** @param[in] p The exponent
**
** @return @b long @b long The result of @p nb raised to the power @p p.
** @retval 0 Returned if @p p is negative.
** @retval 1 Returned if @p p is 0.
**/
long long my_compute_power_rec(int nb, int p);

/**
** @brief Calculates the power of an integer iteratively
**
** @param[in] n The base number
** @param[in] p The exponent
**
** @return @b long @b long The result of @p n raised to the power @p p.
** @retval 0 Returned if @p p is negative.
** @retval 1 Returned if @p p is 0.
**/
long long my_ipow(int n, int p);

/**
** @brief Calculates the square root of an integer
**
** @param[in] nb The target integer
**
** @return @b int The whole square root of @p nb
** @retval 0 Returned if @p nb has no perfect whole square root,
** or if @p nb is negative.
**/
int my_compute_square_root(int nb);

/**
** @brief Calculates the factorial of an integer iteratively
**
** @param[in] n The target integer
**
** @return @b long The factorial of @p n
** @retval 0 Returned if @p n is negative or if an overflow occurs.
**/
long my_factorial(int n);

/**
** @brief Calculates the exponential of an integer
**
** Computes the value of Euler's number @ref E raised to the power
** of @p n ($e^n$).
**
** @param[in] n The exponent to raise @ref E to
**
** @return @b double The resulting value of $e^n$.
** @retval 1.0 Returned if @p n is 0.
**/
//double my_exp(int n);

/*
** -_-
** PRIMES
** -_-
*/

/**
** @brief Checks if a given integer is a prime number
**
** @param[in] nb The number to check
**
** @return @b int A boolean flag indicating if the number is prime
** @retval 1 If @p nb is prime.
** @retval 0 If @p nb is not prime.
**/
int my_is_prime(int nb);

/**
** @brief Finds the closest prime number greater than or equal to the input
**
** @param[in] nb The initial integer
**
** @return @b int The smallest prime number that is greater than
** or equal to @p nb
**/
int my_find_prime_sup(int nb);


/*
** -_-
** ROUNDS
** -_-
*/

/**
** @brief Calculates the ceiling of a value
** (rounds up towards positive infinity)
**
** @param[in] x The double to round up
**
** @return @b double The ceiling value of @p x
**/
double my_ceil(double x);

/**
** @brief Calculates the floor of a value
** (rounds down towards negative infinity)
**
** @param[in] x The double to round down
**
** @return @b double The floor value of @p x
**/
double my_floor(double x);

/**
** @brief Rounds a double to the nearest integer
**
** @param[in] x The double to round
**
** @return @b double The rounded value of @p x
** (halfway cases rounded away from zero)
**/
double my_round(double x);

/**
** @brief Returns the integer part of a double by truncating toward zero
**
** @param[in] x The double to truncate
**
** @return @b double The truncated integer value of @p x
**/
double my_trunc(double x);

#endif /* !DKZ_MATH_H_ */
