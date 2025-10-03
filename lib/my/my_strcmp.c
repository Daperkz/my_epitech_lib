/*
** EPITECH PROJECT, 2025
** my_strcmp
** File description:
** compares to string
*/

static int is_neg(char a, char b)
{
    if (a < b)
        return -1;
    return 1;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i]) {

        i++;
    }
    return (s1[i] > s2[i]) - (s2[i] > s1[i]);
}
