/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** returns a number, sent to the function as a string
*/

static int is_num(char c)
{
    return ('0' <= c && c <= '9');
}

int my_getnbr(char const *str)
{
    int start;
    int i = 0;
    int result = 0;

    while (!is_num(str[i])) {
        i++;
    }
    start = i;
    while (is_num(str[i])) {
        result = ((result * 10) + (str[i] - '0'));
        i++;
    }
    if (str[start - 1] == '-')
        return -result;
    return result;
}
