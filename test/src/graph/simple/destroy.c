/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** destroy
*/

#include "test.h"

Test(ll_destroy, null_parameters)
{
    ll_destroy(NULL, NULL);
}

Test(ll_destroy, basic)
{
    ll_t *list = ll_create();

    cr_assert_not_null(list);
    ll_destroy(list, NULL);
}
