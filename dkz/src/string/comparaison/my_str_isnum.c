/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_str_isnum
** returns 1 if the string passed as parameter only contains digits and 0
** otherwise.
*/

int my_str_isnum(char const *str)
{
    while (*str) {
        if (!(*str >= '0' && *str <= '9')) {
            return 0;
        }
        str++;
    }
    return 1;
}
