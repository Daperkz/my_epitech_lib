/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** dump
*/

#include "test.h"

static void dump_data(void *data)
{
    char *c = (char *)data;

    write(1, c, 1);
}

Test(ll_dump, null_entry)
{
    ll_t *list = {0};

    ll_dump(NULL, &dump_data);
    ll_dump(list, NULL);
}

Test(ll_dump, basic, .init = cr_redirect_stdout)
{
    ll_t *list = ll_create();
    char *data = "A";

    cr_assert_eq(ll_insert(list, data), EXIT_SUCCESS);
    ll_dump(list, &dump_data);
    cr_assert_stdout_eq_str("A");
    ll_destroy(list, NULL);
}

Test(ll_dump, no_dump_function_and_list_not_empty)
{
    ll_t *list = ll_create();
    char *data = "A";

    cr_assert_eq(ll_insert(list, data), EXIT_SUCCESS);
    ll_dump(list, NULL);
    ll_destroy(list, NULL);
}
