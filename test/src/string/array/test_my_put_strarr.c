/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_put_strarr
*/

#include "test.h"

Test(my_put_strarr, standard_output, .init = cr_redirect_stdout)
{
    char *arr[] = {"word1", "word2", "word3", NULL};

    my_put_strarr(arr, '|');
    cr_assert_stdout_eq_str("word1|word2|word3");
}

Test(my_put_strarr, single_element, .init = cr_redirect_stdout)
{
    char *arr[] = {"only", NULL};

    my_put_strarr(arr, ',');
    cr_assert_stdout_eq_str("only");
}

Test(my_put_strarr, null_safety, .init = cr_redirect_stdout)
{
    my_put_strarr(NULL, ' ');
    cr_assert_stdout_eq_str("");
}
