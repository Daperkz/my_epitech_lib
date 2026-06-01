/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_manipulation
*/

#include "test.h"

Test(my_memcpy, basic)
{
    int size = 10;
    int dest[10];
    int src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    my_memcpy(dest, src, size);
    cr_assert_arr_eq(dest, src, size);
}

Test(my_memcpy, null_entry)
{
    int arr[10];

    cr_assert_null(my_memcpy(NULL, arr, 0));
    cr_assert_null(my_memcpy(arr, NULL, 0));
}

Test(my_strlen, basic)
{
    cr_assert_eq(my_strlen("Hello"), 5);
    cr_assert_eq(my_strlen(""), 0);
    cr_assert_eq(my_strlen(" "), 1);
    cr_assert_eq(my_strlen(NULL), 0);
}

Test(my_strcpy, copy_logic)
{
    char dest[10];

    cr_assert_eq(my_strcpy(dest, "Hello"), dest);
    cr_assert_str_eq(dest, "Hello");
    my_strcpy(dest, "");
    cr_assert_str_eq(dest, "");
}

Test(my_strncpy, copy_logic)
{
    char dest[10] = {0};

    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
    my_strncpy(dest, "Hi", 5);
    cr_assert_str_eq(dest, "Hi");
}

Test(my_strdup, memory)
{
    char *dup = my_strdup("Unique");

    cr_assert_str_eq(dup, "Unique");
    free(dup);
    cr_assert_eq(my_strdup(NULL), NULL);
}

Test(my_revstr, basic)
{
    char s1[] = "Hello";
    char s2[] = "a";
    char s3[] = "";

    cr_assert_str_eq(my_revstr(s1), "olleH");
    cr_assert_str_eq(my_revstr(s2), "a");
    cr_assert_str_eq(my_revstr(s3), "");
}

Test(my_strcat, concat)
{
    char dest[20] = "Hello";
    char dest2[10] = "";

    cr_assert_str_eq(my_strcat(dest, " World"), "Hello World");
    cr_assert_str_eq(my_strcat(dest, ""), "Hello World");
    cr_assert_str_eq(my_strcat(dest2, "Hi"), "Hi");
}
