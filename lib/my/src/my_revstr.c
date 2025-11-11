/*
** EPITECH PROJECT, 2025
** my_revstr
** File description:
** reverses a string
*/

static int len(char *str)
{
    int result = 0;

    while (str[result] != '\0') {
        result++;
    }
    return result - 1;
}

char *my_revstr(char *str)
{
    int size = len(str);
    int half = (size / 2) + (size % 2);
    int i = 0;
    char temp;

    while (i < half) {
        temp = str[i];
        str[i] = str[size - i];
        str[size - i] = temp;
        i++;
    }
    return str;
}
