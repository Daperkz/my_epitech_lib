/*
** EPITECH PROJECT, 2026
** my_print_word_array.c
** File description:
** my_print_word_array
*/

#include "io_utils.h"
#include "string_utils.h"

void my_print_word_array(char **word_array, char sep)
{
    while (*word_array) {
        my_putstr(*word_array);
        my_putchar(sep);
        word_array++;
    }
}
