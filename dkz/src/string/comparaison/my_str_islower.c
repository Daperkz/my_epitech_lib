/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_str_islower
** returns 1 if the string passed as parameter only contains lowercase
** alphabetical char- acters and 0 otherwise.
*/

int my_str_islower(char const *str)
{
    while (*str) {
        if (!(*str >= 'a' && *str <= 'z')) {
            return 0;
        }
        str++;
    }
    return 1;
}
