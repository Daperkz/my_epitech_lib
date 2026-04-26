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
    while (*str) {
        if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))) {
            return 0;
        }
        str++;
    }
    return 1;
}
