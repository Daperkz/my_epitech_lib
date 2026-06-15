/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_node
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

Test(destroy_node, null_parameters)
{
    int data = 42;
    node_t *node = create_node(&data);

    cr_assert_not_null(node);
    destroy_node(node, NULL);
    destroy_node(NULL, free);
    destroy_node(NULL, NULL);
}

Test(destroy_node, null_data)
{
    node_t *node = create_node(NULL);

    cr_assert_not_null(node);
    destroy_node(node, free);
}

Test(destroy_node, freeble_data)
{
    node_t *node;
    char *str;
    
    str = my_strdup("Hello");
    cr_assert_not_null(str);
    node = create_node(str);
    cr_assert_not_null(node);
    destroy_node(node, free);
}

Test(destroy_dnode, null_parameters)
{
    int data = 42;
    dnode_t *node = create_dnode(&data);

    cr_assert_not_null(node);
    destroy_dnode(node, NULL);
    destroy_dnode(NULL, free);
    destroy_dnode(NULL, NULL);
}

Test(destroy_dnode, null_data)
{
    dnode_t *node = create_dnode(NULL);

    cr_assert_not_null(node);
    destroy_dnode(node, free);
}

Test(destroy_dnode, freeble_data)
{
    dnode_t *node;
    char *str;
    
    str = my_strdup("Hello");
    cr_assert_not_null(str);
    node = create_dnode(str);
    cr_assert_not_null(node);
    destroy_dnode(node, free);
}

Test(destroy_bnode, null_parameters)
{
    int data = 42;
    bnode_t *node = create_bnode(&data);

    cr_assert_not_null(node);
    destroy_bnode(node, NULL);
    destroy_bnode(NULL, free);
    destroy_bnode(NULL, NULL);
}

Test(destroy_bnode, null_data)
{
    bnode_t *node = create_bnode(NULL);

    cr_assert_not_null(node);
    destroy_bnode(node, free);
}

Test(destroy_bnode, freeble_data)
{
    bnode_t *node;
    char *str;
    
    str = my_strdup("Hello");
    cr_assert_not_null(str);
    node = create_bnode(str);
    cr_assert_not_null(node);
    destroy_bnode(node, free);
}

Test(destroy_bnode_recursive, null_parameters)
{
    destroy_bnode_recursive(NULL, NULL);
}

Test(destroy_bnode_recursive, basic_tree)
{
    bnode_t *root;
    int root_val = 1;
    int left_val = 2;
    int right_val = 3;

    root = create_bnode(&root_val);
    cr_assert_not_null(root);
    root->left = create_bnode(&left_val);
    root->right = create_bnode(&right_val);
    cr_assert_not_null(root->left);
    cr_assert_not_null(root->right);
    destroy_bnode_recursive(root, NULL);
}