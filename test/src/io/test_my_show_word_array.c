/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_show_word_array
*/

#include "test.h"

Test(my_show_word_array, null_parameter, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_show_word_array(NULL), 0);
    cr_assert_stdout_eq_str("");
}

Test(my_show_word_array, basic, .init = cr_redirect_stdout)
{
    char *tab[] = {"Hello", "World", NULL};

    cr_assert_eq(my_show_word_array(tab), 12);
    cr_assert_stdout_eq_str("Hello\nWorld\n");
}

Test(my_show_word_array, single_element, .init = cr_redirect_stdout)
{
    char *tab[] = {"OnlyOne", NULL};

    cr_assert_eq(my_show_word_array(tab), 8);
    cr_assert_stdout_eq_str("OnlyOne\n");
}
