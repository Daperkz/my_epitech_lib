/*
** EPITECH PROJECT, 2025
** my_strcmp
** File description:
** compares to string
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    char c1 = s1[i];
    char c2 = s2[i];

    while ((c1 || c2) && c1 == c2) {
        i++;
        c1 = s1[i];
        c2 = s2[i];
    }
    return (c1 > c2) - (c1 < c2);
}
