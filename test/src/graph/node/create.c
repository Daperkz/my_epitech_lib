/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** create
*/

#include "test.h"

Test(create_node, success)
{
    int data = 42;
    node_t *node = create_node(&data);

    cr_assert_not_null(node);
    cr_assert_eq(node->data, &data);
    cr_assert_null(node->next);
    destroy_node(node, NULL);
}

Test(create_node, malloc_fail, .fini = reset_malloc_wrapper)
{
    int data = 42;

    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(create_node(&data));
}

Test(create_dnode, success)
{
    int data = 84;
    dnode_t *node = create_dnode(&data);

    cr_assert_not_null(node);
    cr_assert_eq(node->data, &data);
    cr_assert_null(node->next);
    cr_assert_null(node->prev);
    destroy_dnode(node, NULL);
}

Test(create_dnode, malloc_fail, .fini = reset_malloc_wrapper)
{
    int data = 84;

    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(create_dnode(&data));
}

Test(create_bnode, success)
{
    int data = 168;
    bnode_t *node = create_bnode(&data);

    cr_assert_not_null(node);
    cr_assert_eq(node->data, &data);
    cr_assert_null(node->left);
    cr_assert_null(node->right);
    destroy_bnode(node, NULL);
}

Test(create_bnode, malloc_fail, .fini = reset_malloc_wrapper)
{
    int data = 168;

    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(create_bnode(&data));
}
