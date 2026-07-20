/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_put_nbr
*/

#include "test.h"

Test(my_put_nbr, limits, .init = cr_redirect_stdout)
{
    my_put_nbr(-2147483647);
    cr_assert_stdout_eq_str("-2147483647");
}

Test(my_put_nbr, zero_case, .init = cr_redirect_stdout)
{
    my_put_nbr(0);
    cr_assert_stdout_eq_str("0");
}

Test(my_put_nbr_base, basic_negative_value, .init = cr_redirect_stdout)
{
    my_put_nbr_base(-6, BASE10);
    cr_assert_stdout_eq_str("-6");
}

Test(my_put_nbr_base, hex_base, .init = cr_redirect_stdout)
{
    my_put_nbr_base(255, BASE16CAP);
    cr_assert_stdout_eq_str("FF");
}

Test(my_put_nbr_base, binary_base, .init = cr_redirect_stdout)
{
    my_put_nbr_base(10, BASE2);
    cr_assert_stdout_eq_str("1010");
}

Test(my_put_nbr_base, invalid_base, .init = cr_redirect_stdout)
{
    int ret = my_put_nbr_base(42, "0");
    cr_assert_eq(ret, 0);
}
