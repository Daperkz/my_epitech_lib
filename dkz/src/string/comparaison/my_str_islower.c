/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_str_islower
** returns 1 if the string passed as parameter only contains lowercase
** alphabetical characters and 0 otherwise.
*/

int my_str_islower(char const *str)
{
    if (!str)
        return (0);
    while (*str) {
        if (*str < 'a' || *str > 'z') {
            return (0);
        }
        str++;
    }
    return (1);
}
