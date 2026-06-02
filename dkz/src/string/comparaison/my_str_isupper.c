/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_str_isupper
** returns 1 if the string passed as parameter only contains uppercase
** alphabetical char- acters and 0 otherwise.
*/

int is_upper(char const c)
{
    return (c >= 'A' && c <= 'Z');
}

int my_str_isupper(char const *str)
{
    if (!str)
        return (0);
    while (*str) {
        if (!is_upper(*str)) {
            return (0);
        }
        str++;
    }
    return (1);
}
