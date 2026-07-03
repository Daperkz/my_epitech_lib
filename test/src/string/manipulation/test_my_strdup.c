/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_strdup
*/

#include "test.h"

Test(my_strdup, memory)
{
    char *dup = my_strdup("Unique");

    cr_assert_str_eq(dup, "Unique");
    free(dup);
    cr_assert_eq(my_strdup(NULL), NULL);
}
