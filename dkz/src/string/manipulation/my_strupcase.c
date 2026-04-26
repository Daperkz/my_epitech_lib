/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_strupcase
** puts every letter in uppercase
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] += ('A' - 'a');
        i++;
    }
    return str;
}
