/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_showmem
*/

#include "test.h"

Test(my_showmem, null_parameters, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_showmem(NULL, 10), 0);
    cr_assert_stdout_eq_str("");
}

Test(my_showmem, zero_or_negative_size, .init = cr_redirect_stdout)
{
    char const *str = "Hello world";

    cr_assert_eq(my_showmem(str, 0), 0);
    cr_assert_eq(my_showmem(str, -5), 0);
    cr_assert_stdout_eq_str("");
}

Test(my_showmem, epitech_subject_example, .init = cr_redirect_stdout)
{
    char const str[] =
        "hey guys show mem is cool you can do some pretty neat stuff"
        "\x00\x0f\x1b\x7f\x05\x2e\x00\x01\x02\x03\x04\x05\x06\x07\x08"
        "\x09\x0e\x0f\x1b\x7f";
    char const *expected =
        "00000000: 6865 7920 6775 7973 2073 686f 7720 6d65 hey guys show me\n"
        "00000010: 6d20 6973 2063 6f6f 6c20 796f 7520 6361 m is cool you ca\n"
        "00000020: 6e20 646f 2073 6f6d 6520 7072 6574 7479 n do some pretty\n"
        "00000030: 206e 6561 7420 7374 7566 6600 0f1b 7f05  neat stuff.....\n"
        "00000040: 2e00 0102 0304 0506 0708 090e 0f1b 7f   ...............\n";

    cr_assert_eq(my_showmem(str, 79), 0);
    cr_assert_stdout_eq_str(expected);
}

Test(my_showmem, incomplete_line_padding, .init = cr_redirect_stdout)
{
    char const *str = "Hello";
    char const *expected =
        "00000000: 4865 6c6c 6f                            Hello\n";

    cr_assert_eq(my_showmem(str, 5), 0);
    cr_assert_stdout_eq_str(expected);
}

Test(my_showmem, exactly_one_full_line, .init = cr_redirect_stdout)
{
    char const *str = "0123456789abcdef";
    char const *expected =
        "00000000: 3031 3233 3435 3637 3839 6162 6364 6566 0123456789abcdef\n";

    cr_assert_eq(my_showmem(str, 16), 0);
    cr_assert_stdout_eq_str(expected);
}

Test(my_showmem, address_hex_letters, .init = cr_redirect_stdout)
{
    char buffer[161] = {0};

    cr_assert_eq(my_showmem(buffer, 161), 0);
}
