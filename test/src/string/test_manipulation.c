/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_manipulation
*/

#include "test.h"

Test(my_memcpy, null_entry)
{
    int arr[10];

    cr_assert_null(my_memcpy(NULL, arr, 1));
    cr_assert_null(my_memcpy(arr, NULL, 1));
}

Test(my_memcpy, basic)
{
    int size = 10;
    int dest[10];
    int src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    my_memcpy(dest, src, sizeof(int) * size);
    cr_assert_arr_eq(dest, src, sizeof(int) * size);
}

Test(my_memmove, null_entry)
{
    int arr[10];

    cr_assert_null(my_memmove(NULL, arr, 1));
    cr_assert_null(my_memmove(arr, NULL, 1));
}

Test(my_memmove, basic)
{
    int size = 5;
    int dest[5];
    int src[] = {1, 2, 3, 4, 5};

    my_memmove(dest, src, sizeof(int) * size);
    cr_assert_arr_eq(dest, src, size);
}

Test(my_memmove, overlap_dest_after_src)
{
    int expected[] = {1, 2, 1, 2, 3};
    int arr[] = {1, 2, 3, 4, 5};

    my_memmove(arr + 2, arr, sizeof(int) * 3);
    cr_assert_arr_eq(arr, expected, 5);
}

Test(my_memmove, overlap_dest_before_src)
{
    int expected[] = {3, 4, 5, 4, 5};
    int arr[] = {1, 2, 3, 4, 5};

    my_memmove(arr, arr + 2, sizeof(int) * 3);
    cr_assert_arr_eq(arr, expected, 5);
}

Test(my_memset, null_entry)
{
    cr_assert_null(my_memset(NULL, 0, 10));
}

Test(my_memset, basic)
{
    int dest[10];
    int target[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    my_memset(dest, 0, 10);
    cr_assert_arr_eq(dest, target, 10);
}

Test(my_putstr, null_entry, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_putstr(NULL), 0);
    cr_assert_stdout_eq_str("");
}

Test(my_putstr, basic, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_putstr("Hello"), 5);
    cr_assert_stdout_eq_str("Hello");
}

Test(my_putnstr, null_entry, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_putnstr(NULL, 0), -1);
    cr_assert_eq(my_putnstr(NULL, 1), -1);
    cr_assert_stdout_eq_str("");
}

Test(my_putnstr, basic, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_putnstr("Hello", 3), 3);
    cr_assert_stdout_eq_str("Hel");
}

Test(my_putnstr, negative_arg, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_putnstr("NO", -2), -1);
    cr_assert_stdout_eq_str("");
}

Test(my_fputstr, null_entry, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_fputstr(STDOUT_FD, NULL), 0);
    cr_assert_stdout_eq_str("");
}

Test(my_fputstr, basic, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_fputstr(STDOUT_FD, "Hello"), 5);
    cr_assert_stdout_eq_str("Hello");
}

Test(my_fputstr, invalid_fd)
{
    cr_assert_eq(my_fputstr(-1, "Hello"), -1);
}

Test(my_fputnstr, null_entry, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_fputnstr(STDOUT_FD, NULL, 0), -1);
    cr_assert_eq(my_fputnstr(STDOUT_FD, NULL, 1), -1);
    cr_assert_stdout_eq_str("");
}

Test(my_fputnstr, basic, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_fputnstr(STDOUT_FD, "Hello", 3), 3);
    cr_assert_stdout_eq_str("Hel");
}

Test(my_fputnstr, negative_arg, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_fputnstr(STDOUT_FD, "NO", -2), -1);
    cr_assert_stdout_eq_str("");
}

Test(my_fputnstr, invalid_fd)
{
    cr_assert_eq(my_fputnstr(-1, "Hello", 5), -1);
}

Test(my_revstr, null_entry)
{
    cr_assert_null(my_revstr(NULL));
}

Test(my_revstr, reverse_odd_sized_string)
{
    char s1[] = "Hello";

    cr_assert_str_eq(my_revstr(s1), "olleH");
}

Test(my_revstr, reverse_even_sized_string)
{
    char str[] = "AB";

    cr_assert_str_eq(my_revstr(str), "BA");
}

Test(my_revstr, special_cases)
{
    char s2[] = "a";
    char s3[] = "";

    cr_assert_str_eq(my_revstr(s2), "a");
    cr_assert_str_eq(my_revstr(s3), "");
}

Test(my_strappend, null_entry)
{
    char *dest = "Won't work";

    cr_assert_null(my_strappend(NULL, "Hello"));
    cr_assert_null(my_strappend(&dest, NULL));
}

Test(my_strappend, basic)
{
    char *dest = malloc(sizeof(char) * 7);
    char src[] = "World!";

    my_strcpy(dest, "Hello ");
    cr_assert_str_eq(my_strappend(&dest, src), "Hello World!");
    free(dest);
}

Test(my_strappend, malloc_fail, .fini = reset_malloc_wrapper)
{
    char *dest = malloc(sizeof(char) * 7);
    char src[] = "World!";

    my_strcpy(dest, "Hello ");
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(my_strappend(&dest, src));
    free(dest);
}

Test(my_strcapitalize, null_entry)
{
    cr_assert_null(my_strcapitalize(NULL));
}

Test(my_strcapitalize, basic)
{
    char src[] = "hello world";
    char target[] = "Hello World";
    cr_assert_str_eq(my_strcapitalize(src), target);
}

Test(my_strcapitalize, uppercase_inword)
{
    char src[] = "helLo worLd";
    char target[] = "Hello World";
    cr_assert_str_eq(my_strcapitalize(src), target);
}

Test(my_strcat, null_entry)
{
    cr_assert_null(my_strcat(NULL, "World"));
    cr_assert_null(my_strcat("Hello", NULL));
}

Test(my_strcat, concat)
{
    char dest[20] = "Hello ";
    char dest2[10] = "";

    cr_assert_str_eq(my_strcat(dest, "World"), "Hello World");
    cr_assert_str_eq(my_strcat(dest, ""), "Hello World");
    cr_assert_str_eq(my_strcat(dest2, "Hi"), "Hi");
}

Test(my_strncat, null_entry)
{
    cr_assert_null(my_strncat(NULL, "World", 1));
    cr_assert_null(my_strncat("Hello ", NULL, 1));
    cr_assert_null(my_strncat("Hello ", "World", -1));
}

Test(my_strncat, concat)
{
    char dest[20] = "Hello ";
    char dest2[10] = "";

    cr_assert_str_eq(my_strncat(dest, "World", 6), "Hello World");
    cr_assert_str_eq(my_strncat(dest, "", 0), "Hello World");
    cr_assert_str_eq(my_strncat(dest2, "Hi", 2), "Hi");
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

Test(my_strjoin, null_entry)
{
    cr_assert_null(my_strjoin(NULL, "World"));
    cr_assert_null(my_strjoin("Hello ", NULL));
}

Test(my_strjoin, basic)
{
    char *str = my_strjoin("Hello ", "World");
    char target[] = "Hello World";

    cr_assert_not_null(str);
    cr_assert_str_eq(str, target);
}

Test(my_strjoin, malloc_fail, .fini = reset_malloc_wrapper)
{
    char *str;

    set_malloc_fail(1);
    set_malloc_count(0);
    str = my_strjoin("Hello ", "World");
    cr_assert_null(str);
}

Test(my_strlen, null_entry)
{
    cr_assert_eq(my_strlen(NULL), 0);
}

Test(my_strlen, basic)
{
    cr_assert_eq(my_strlen("Hello"), 5);
    cr_assert_eq(my_strlen(""), 0);
    cr_assert_eq(my_strlen(" "), 1);
}

Test(my_strlen_d, null_entry)
{
    cr_assert_eq(my_strlen_d(NULL, 'c'), 0);
}

Test(my_strlen_d, basic)
{
    cr_assert_eq(my_strlen_d("Hello", 'l'), 2);
    cr_assert_eq(my_strlen_d("", 'l'), 0);
    cr_assert_eq(my_strlen_d(" ", 'l'), 1);
}

Test(my_strlowcase, null_entry)
{
    cr_assert_null(my_strlowcase(NULL));
}

Test(my_strlowcase, basic)
{
    char src1[] = "HelLO WoRLD!{2}";
    char target1[] = "hello world!{2}";
    char src2[] = "ABC";
    char target2[] = "abc";

    cr_assert_str_eq(my_strlowcase(src1), target1);
    cr_assert_str_eq(my_strlowcase(src2), target2);
}

Test(my_strtrim, null_entry)
{
    cr_assert_null(my_strtrim(NULL, "la"));
    cr_assert_null(my_strtrim("world", NULL));
}

Test(my_strtrim, basic)
{
    char src[] = "   Hello World !  ka";
    char seps[] = " ka";
    char target[] = "Hello World !";

    cr_assert_str_eq(my_strtrim(src, seps), target);
}

Test(my_strupcase, null_entry)
{
    cr_assert_null(my_strupcase(NULL));
}

Test(my_strupcase, basic)
{
    char src1[] = "HellO WoRLD!{2}";
    char target1[] = "HELLO WORLD!{2}";
    char src2[] = "abc";
    char target2[] = "ABC";

    cr_assert_str_eq(my_strupcase(src1), target1);
    cr_assert_str_eq(my_strupcase(src2), target2);
}
