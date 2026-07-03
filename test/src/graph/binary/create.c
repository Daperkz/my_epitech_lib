/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** create
*/

#include "test.h"

Test(btree_create, malloc_fail, .fini = reset_malloc_wrapper)
{
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(btree_create());
}
