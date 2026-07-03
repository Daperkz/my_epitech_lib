/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** modifiers.h
** all modifiers
*/

#ifndef DKZ_PRINTF_MODIFIER_H_
    #define DKZ_PRINTF_MODIFIER_H_

    #include "internal.h"

char *apply_width(char *str, pf_info_t *info);
char *apply_precision(char *str, pf_info_t *info, char specifier);
char *apply_sign_flags(char *str, pf_info_t *info, char specifier);
char *apply_sharp_flag(char *str, char specifier);

#endif /* !DKZ_PRINTF_MODIFIER_H */
