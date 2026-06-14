/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_bintree
*/

#include "test.h"

static int compare_ints(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

Test(btree_insert, null_parameters)
{
    int data = 42;
    btree_t tree = {0};

    cr_assert_eq(btree_insert(NULL, &data, compare_ints), EXIT_FAILURE);
    cr_assert_eq(btree_insert(&tree, &data, NULL), EXIT_FAILURE);
}

Test(btree_insert, insert_root_node_succeeds)
{
    btree_t *tree = btree_create();
    int root_val = 50;

    cr_assert_not_null(tree);
    cr_assert_eq(btree_insert(tree, &root_val, compare_ints), EXIT_SUCCESS);
    cr_assert_eq(tree->size, 1);
    cr_assert_not_null(tree->root);
    cr_assert_eq(*(int *)(tree->root->data), 50);
    btree_destroy(tree, NULL);
}

Test(btree_insert, insert_smaller_value_goes_left)
{
    btree_t *tree = btree_create();
    int root_val = 50;
    int left_val = 25;

    cr_assert_not_null(tree);
    btree_insert(tree, &root_val, compare_ints);
    cr_assert_eq(btree_insert(tree, &left_val, compare_ints), EXIT_SUCCESS);
    cr_assert_eq(tree->size, 2);
    cr_assert_not_null(tree->root->left);
    cr_assert_eq(*(int *)(tree->root->left->data), 25);
    btree_destroy(tree, NULL);
}

Test(btree_insert, insert_larger_value_goes_right)
{
    btree_t *tree = btree_create();
    int root_val = 50;
    int right_val = 75;

    cr_assert_not_null(tree);
    btree_insert(tree, &root_val, compare_ints);
    cr_assert_eq(btree_insert(tree, &right_val, compare_ints), EXIT_SUCCESS);
    cr_assert_eq(tree->size, 2);
    cr_assert_not_null(tree->root->right);
    cr_assert_eq(*(int *)(tree->root->right->data), 75);
    btree_destroy(tree, NULL);
}

Test(btree_insert, insert_duplicate_value_goes_right)
{
    btree_t *tree = btree_create();
    int root_val = 50;
    int duplicate_val = 50;

    cr_assert_not_null(tree);
    btree_insert(tree, &root_val, compare_ints);
    cr_assert_eq(btree_insert(tree, &duplicate_val, compare_ints), EXIT_SUCCESS);
    cr_assert_eq(tree->size, 2);
    cr_assert_not_null(tree->root->right);
    cr_assert_eq(*(int *)(tree->root->right->data), 50);
    btree_destroy(tree, NULL);
}

Test(btree_insert, malloc_fail, .fini = reset_malloc_wrapper)
{
    btree_t *tree = btree_create();
    int root_val = 50;

    cr_assert_not_null(tree);
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_eq(btree_insert(tree, &root_val, compare_ints), EXIT_FAILURE);
    btree_destroy(tree, NULL);
}

Test(btree_create, malloc_fail, .fini = reset_malloc_wrapper)
{
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(btree_create());
}

Test(btree_destroy, null_entry)
{
    btree_destroy(NULL, NULL);
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
