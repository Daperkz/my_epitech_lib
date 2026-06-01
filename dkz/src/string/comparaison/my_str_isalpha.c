/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_str_isalpha
** returns 1 if the string passed as parameter only contains alphabetical
** characters and 0 if the string contains another type of character.
*/

int my_str_isalpha(char const *str)
{
    if (!str)
        return (0);
    while (*str) {
        if ((*str < 'A' || *str > 'Z') && (*str < 'a' || *str > 'z')) {
            return (0);
        }
        str++;
    }
    return (1);
}
