/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** pop
*/

#include "test.h"

static int compare_ints(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

Test(btree_pop, null_parameters)
{
    btree_t *tree = btree_create();
    int ref = 42;

    cr_assert_not_null(tree);
    cr_assert_null(btree_pop(NULL, &ref, compare_ints));
    cr_assert_null(btree_pop(tree, &ref, compare_ints));
    cr_assert_eq(btree_insert(tree, &ref, compare_ints), EXIT_SUCCESS);
    cr_assert_null(btree_pop(tree, &ref, NULL));
    btree_destroy(tree, NULL);
}

Test(btree_pop, empty_tree)
{
    btree_t *tree = btree_create();
    int ref = 42;

    cr_assert_not_null(tree);
    cr_assert_null(btree_pop(tree, &ref, compare_ints));
    btree_destroy(tree, NULL);
}

Test(btree_pop, search_non_existent_element)
{
    btree_t *tree = btree_create();
    int root_val = 50;
    int missing_val = 100;

    cr_assert_not_null(tree);
    btree_insert(tree, &root_val, compare_ints);
    cr_assert_null(btree_pop(tree, &missing_val, compare_ints));
    cr_assert_eq(tree->size, 1);
    btree_destroy(tree, NULL);
}

Test(btree_pop, pop_leaf_node)
{
    btree_t *tree = btree_create();
    int root_val = 50;
    int left_val = 25;
    int *result;

    cr_assert_not_null(tree);
    btree_insert(tree, &root_val, compare_ints);
    btree_insert(tree, &left_val, compare_ints);
    result = btree_pop(tree, &left_val, compare_ints);
    cr_assert_not_null(result);
    cr_assert_eq(*result, 25);
    cr_assert_eq(tree->size, 1);
    cr_assert_null(tree->root->left);
    btree_destroy(tree, NULL);
}

Test(btree_pop, pop_node_with_one_child)
{
    btree_t *tree = btree_create();
    int root_val = 50;
    int left_val = 25;
    int grandchild_val = 12;
    int *result;

    cr_assert_not_null(tree);
    btree_insert(tree, &root_val, compare_ints);
    btree_insert(tree, &left_val, compare_ints);
    btree_insert(tree, &grandchild_val, compare_ints);
    result = btree_pop(tree, &left_val, compare_ints);
    cr_assert_not_null(result);
    cr_assert_eq(*result, 25);
    cr_assert_eq(tree->size, 2);
    cr_assert_not_null(tree->root->left);
    cr_assert_eq(*(int *)(tree->root->left->data), 12);
    btree_destroy(tree, NULL);
}

Test(btree_pop, pop_node_with_two_children)
{
    btree_t *tree = btree_create();
    int vals[] = {50, 25, 75, 60, 85};
    int target = 75;
    int *result;

    cr_assert_not_null(tree);
    for (size_t i = 0; i < 5; i++)
        btree_insert(tree, &vals[i], compare_ints);
    result = btree_pop(tree, &target, compare_ints);
    cr_assert_not_null(result);
    cr_assert_eq(*result, 75);
    cr_assert_eq(tree->size, 4);
    cr_assert_not_null(tree->root->right);
    cr_assert_eq(*(int *)(tree->root->right->data), 85);
    cr_assert_not_null(tree->root->right->left);
    cr_assert_eq(*(int *)(tree->root->right->left->data), 60);
    btree_destroy(tree, NULL);
}

/* Structure:
**         50  <-- Target to pop (Root)
**       /    \
**     25      75
**            /
**          60
**         /
**       55    <-- In-order successor (deepest left child)
*/
Test(btree_pop, pop_node_with_two_children_deep_left_successor)
{
    btree_t *tree = btree_create();
    int vals[] = {50, 25, 75, 60, 55};
    int target = 50;
    int *result;

    cr_assert_not_null(tree);
    for (size_t i = 0; i < 5; i++)
        btree_insert(tree, &vals[i], compare_ints);
    result = btree_pop(tree, &target, compare_ints);
    cr_assert_not_null(result);
    cr_assert_eq(*result, 50);
    cr_assert_eq(tree->size, 4);
    cr_assert_eq(*(int *)(tree->root->data), 55);
    cr_assert_eq(*(int *)(tree->root->left->data), 25);
    cr_assert_eq(*(int *)(tree->root->right->data), 75);
    cr_assert_eq(*(int *)(tree->root->right->left->data), 60);
    cr_assert_null(tree->root->right->left->left);
    btree_destroy(tree, NULL);
}
