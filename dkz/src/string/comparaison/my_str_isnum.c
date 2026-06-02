/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_str_isnum
** returns 1 if the string passed as parameter only contains digits and 0
** otherwise.
*/

int is_num(char const c)
{
    return (c >= '0' && c <= '9');
}

int my_str_isnum(char const *str)
{
    if (!str)
        return (0);
    while (*str) {
        if (!is_num(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}
