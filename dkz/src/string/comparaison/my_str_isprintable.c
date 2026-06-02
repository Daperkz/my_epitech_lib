/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_str_isprintable
** returns 1 if the string passed as parameter only contains printable
** characters and 0 otherwise.
*/

int is_printable(char const c)
{
    return !(c <= 31 || c == 127);
}

int my_str_isprintable(char const *str)
{
    if (!str)
        return (0);
    while (*str) {
        if (!is_printable(*str)) {
            return (0);
        }
        str++;
    }
    return (1);
}
