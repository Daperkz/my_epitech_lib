/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_show_word_array
** displays the content of an array of words.
** There is one word per line, and each word ends with '\n',
** including the last one.
*/

#include <stdlib.h>

#include "dkz/string.h"
#include "dkz/io.h"

int my_show_word_array(char **tab)
{
    int printed = 0;

    if (!tab)
        return (0);
    while (*tab) {
        printed += my_putstr(*tab);
        printed += my_putchar('\n');
        tab++;
    }
    return (printed);
}
