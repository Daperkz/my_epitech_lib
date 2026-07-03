/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** create
*/

#include "test.h"

Test(ll_create, success)
{
    ll_t *list = ll_create();

    cr_assert_not_null(list);
    ll_destroy(list, NULL);
}

Test(ll_create, malloc_fail, .fini = reset_malloc_wrapper)
{
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(ll_create());
}
