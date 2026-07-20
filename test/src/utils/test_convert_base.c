/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_convert_base
*/

#include "test.h"

Test(convert_base, null_safety)
{
    cr_assert_null(convert_base(NULL, BASE10, BASE2));
    cr_assert_null(convert_base("42", NULL, BASE2));
    cr_assert_null(convert_base("42", BASE10, NULL));
}

Test(convert_base, small_bases_inferior_two)
{
    cr_assert_null(convert_base("42", "0", BASE10));
    cr_assert_null(convert_base("42", BASE10, ""));
}

Test(convert_base, bases_with_duplicates)
{
    cr_assert_null(convert_base("42", "01234556", BASE10));
    cr_assert_null(convert_base("42", BASE10, "ABA"));
}

Test(convert_base, bases_with_sign_char)
{
    cr_assert_null(convert_base("42", "0123+4", BASE10));
    cr_assert_null(convert_base("42", BASE10, "01-23"));
}

Test(convert_base, zero_value)
{
    char *res = convert_base("0", BASE10, BASE2);

    cr_assert_not_null(res);
    cr_assert_str_eq(res, "0");
    free(res);
}

Test(convert_base, BASE10_to_BASE2)
{
    char *res = convert_base("42", BASE10, BASE2);

    cr_assert_not_null(res);
    cr_assert_str_eq(res, "101010");
    free(res);
}

Test(convert_base, BASE2_to_BASE16CAP)
{
    char *res = convert_base("11111111", BASE2, BASE16CAP);

    cr_assert_not_null(res);
    cr_assert_str_eq(res, "FF");
    free(res);
}

Test(convert_base, BASE16CAP_to_BASE10)
{
    char *res = convert_base("2A", BASE16CAP, BASE10);

    cr_assert_not_null(res);
    cr_assert_str_eq(res, "42");
    free(res);
}

Test(convert_base, negative_numbers)
{
    char *res = convert_base("-42", BASE10, BASE2);

    cr_assert_not_null(res);
    cr_assert_str_eq(res, "-101010");
    free(res);
}

Test(convert_base, multiple_signs)
{
    char *res1 = convert_base("--42", BASE10, BASE2);
    char *res2 = convert_base("+-+42", BASE10, BASE2);

    cr_assert_not_null(res1);
    cr_assert_str_eq(res1, "101010");
    free(res1);
    cr_assert_not_null(res2);
    cr_assert_str_eq(res2, "-101010");
    free(res2);
}

Test(convert_base, custom_alphabets)
{
    char const *base_pogo = "pogO";
    char *res = convert_base("3", BASE10, base_pogo);

    cr_assert_not_null(res);
    cr_assert_str_eq(res, "O");
    free(res);
}

Test(convert_base, malloc_fail, .fini = reset_malloc_wrapper)
{
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(convert_base("42", BASE10, BASE2));
}

Test(convert_base, invalid_char_in_nbr)
{
    char *res = convert_base("1021", BASE2, BASE10);

    cr_assert_not_null(res);
    cr_assert_str_eq(res, "2");
    free(res);
}

Test(convert_base, no_valid_digits)
{
    char *res = convert_base("ABC", BASE10, BASE2);

    cr_assert_not_null(res);
    cr_assert_str_eq(res, "0");
    free(res);
}
