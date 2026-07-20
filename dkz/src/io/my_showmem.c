/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** my_showmem.c
*/

#include "dkz/string.h"
#include "dkz/io.h"

static void print_address(int offset)
{
    int nibble;

    for (int i = 28; i >= 0; i -= 4) {
        nibble = (offset >> i) & 0xF;
        if (nibble < 10) {
            my_putchar('0' + nibble);
        } else {
            my_putchar('a' + (nibble - 10));
        }
    }
    my_putstr(": ");
}

static void hex_zero_padding(char c)
{
    if (c < 16)
        my_putchar('0');
}

static void print_line_hex(char const *str, int size, int offset)
{
    unsigned char c;

    for (int i = 0; i < 16; i++) {
        if (offset + i < size) {
            c = (unsigned char)str[offset + i];
            hex_zero_padding(c);
            my_put_nbr_base(c, "0123456789abcdef");
        } else {
            my_putstr("  ");
        }
        if (i % 2 == 1) {
            my_putchar(' ');
        }
    }
}

static void print_line_printable(char const *str, int size, int offset)
{
    unsigned char c;

    for (int i = 0; i < 16 && offset + i < size; i++) {
        c = (unsigned char)str[offset + i];
        if (c >= 32 && c <= 126) {
            my_putchar(c);
        } else {
            my_putchar('.');
        }
    }
}

int my_showmem(char const *str, int size)
{
    if (!str || size <= 0)
        return 0;
    for (int offset = 0; offset < size; offset += 16) {
        print_address(offset);
        print_line_hex(str, size, offset);
        print_line_printable(str, size, offset);
        my_putchar('\n');
    }
    return 0;
}
