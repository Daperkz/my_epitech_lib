/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** get
*/

#include "test.h"

static int compare_ints(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

Test(btree_get, null_parameters)
{
    btree_t *tree = btree_create();
    int ref = 42;

    cr_assert_not_null(tree);
    cr_assert_null(btree_get(NULL, &ref, compare_ints));
    cr_assert_null(btree_get(tree, &ref, NULL));
    btree_destroy(tree, NULL);
}

Test(btree_get, empty_tree)
{
    btree_t *tree = btree_create();
    int ref = 42;

    cr_assert_not_null(tree);
    cr_assert_null(btree_get(tree, &ref, compare_ints));
    btree_destroy(tree, NULL);
}

Test(btree_get, find_root_element)
{
    btree_t *tree = btree_create();
    int val = 50;
    int *result;

    cr_assert_not_null(tree);
    btree_insert(tree, &val, compare_ints);
    result = btree_get(tree, &val, compare_ints);
    cr_assert_not_null(result);
    cr_assert_eq(*result, 50);
    btree_destroy(tree, NULL);
}

Test(btree_get, navigate_left_and_find_element)
{
    btree_t *tree = btree_create();
    int root_val = 50;
    int left_val = 25;
    int *result;

    cr_assert_not_null(tree);
    btree_insert(tree, &root_val, compare_ints);
    btree_insert(tree, &left_val, compare_ints);
    result = btree_get(tree, &left_val, compare_ints);
    cr_assert_not_null(result);
    cr_assert_eq(*result, 25);
    btree_destroy(tree, NULL);
}

Test(btree_get, navigate_right_and_find_element)
{
    btree_t *tree = btree_create();
    int root_val = 50;
    int right_val = 75;
    int *result;

    cr_assert_not_null(tree);
    btree_insert(tree, &root_val, compare_ints);
    btree_insert(tree, &right_val, compare_ints);
    result = btree_get(tree, &right_val, compare_ints);
    cr_assert_not_null(result);
    cr_assert_eq(*result, 75);
    btree_destroy(tree, NULL);
}

Test(btree_get, search_non_existent_element)
{
    btree_t *tree = btree_create();
    int root_val = 50;
    int missing_val = 100;

    cr_assert_not_null(tree);
    btree_insert(tree, &root_val, compare_ints);
    cr_assert_null(btree_get(tree, &missing_val, compare_ints));
    btree_destroy(tree, NULL);
}
