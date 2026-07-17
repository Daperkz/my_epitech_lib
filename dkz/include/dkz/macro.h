/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** macro.h
*/
/**
** @file macro.h
** @brief Header file for system-wide macros and standard exit codes.
**
** This file provides fallback definitions for standard macros and defines
** common program execution exit codes used across the libdkz library.
**
** @author Daperkz
** @ingroup libdkz
** @version 1.0
** @date 2026-07-16
*/

#ifndef DKZ_MACRO_H_
    #define DKZ_MACRO_H_

    #ifndef NULL
        /**
        ** @brief Null pointer constant definition
        **/
        #define NULL ((void *)0)
    #endif

    /**
    ** @brief Exit code indicating successful program execution
    **/
    #define EXIT_SUCCESS 0

    /**
    ** @brief Exit code indicating a standard program failure
    **/
    #define EXIT_FAILURE 1

    /**
    ** @brief Exit code indicating a process or
    ** operation has successfully finished
    **/
    #define EXIT_DONE 2

    /**
    ** @brief Epitech-specific exit code indicating an error occurred
    **/
    #define EXIT_ERROR 84


#endif /* !DKZ_MACRO_H_ */
