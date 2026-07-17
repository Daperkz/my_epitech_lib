/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** node
*/
/**
** @file node.h
** @brief Header file for various node types (single, double, binary) used
** in graph and list structures.
**
** This file contains definitions and manipulation functions
** for basic data nodes, supporting single-linked, double-linked,
** and binary-tree structures.
**
** @author Daperkz
** @ingroup libdkz
** @test ./test/src/graph/node/
** @version 1.0
** @date 2026-07-17
*/

#ifndef DKZ_NODE_H_
    #define DKZ_NODE_H_

/*
** -_-
** SINGLE NODE
** -_-
*/

/**
** @brief Structure representing a single-linked node.
**/
typedef struct node_s {
    void *data;
    struct node_s *next;
} node_t;

/**
** @brief Creates and allocates a new single node
**
** @param[in] data Pointer to the generic data to store inside the node.
**
** @return @b node_t* Pointer to the newly allocated single node structure.
** @retval NULL Returned if memory allocation fails.
**/
node_t *create_node(void *data);

/**
** @brief Destroys and frees a single node
**
** @param[in, out] node Pointer to the node to destroy.
** @param[in] free_data Function pointer to free the stored generic data.
** If NULL, the data stored inside the node will not be freed.
**
** @return @b void
**/
void destroy_node(node_t *node, void (*free_data)(void *));

/*
** -_-
** DOUBLE NODE
** -_-
*/

/**
** @brief Structure representing a double-linked node.
**/
typedef struct double_node_s {
    void *data;
    struct double_node_s *prev;
    struct double_node_s *next;
} dnode_t;

/**
** @brief Creates and allocates a new double node
**
** @param[in] data Pointer to the generic data to store inside the node.
**
** @return @b dnode_t* Pointer to the newly allocated double node structure.
** @retval NULL Returned if memory allocation fails.
**/
dnode_t *create_dnode(void *data);

/**
** @brief Destroys and frees a double node
**
** @param[in, out] node Pointer to the double node to destroy.
** @param[in] free_data Function pointer to free the stored generic data.
** If NULL, the data stored inside the node will not be freed.
**
** @return @b void
**/
void destroy_dnode(dnode_t *node, void (*free_data)(void *));

/*
** -_-
** BINARY NODE
** -_-
*/

/**
** @brief Structure representing a binary-tree node.
**/
typedef struct binary_node_s {
    void *data;
    struct binary_node_s *left;
    struct binary_node_s *right;
} bnode_t;

/**
** @brief Creates and allocates a new binary node
**
** @param[in] data Pointer to the generic data to store inside the node.
**
** @return @b bnode_t* Pointer to the newly allocated binary node structure.
** @retval NULL Returned if memory allocation fails.
**/
bnode_t *create_bnode(void *data);

/**
** @brief Destroys and frees a single binary node
**
** @warning This function does not free the child nodes. Doing so without
** preserving pointers will lead to memory leaks.
**
** @param[in, out] node Pointer to the binary node to destroy.
** @param[in] free_data Function pointer to free the stored generic data.
** If NULL, the data stored inside the node will not be freed.
**
** @return @b void
**/
void destroy_bnode(bnode_t *node, void (*free_data)(void *));

/**
** @brief Recursively destroys a binary node and all its child subtrees
**
** Traverses down both @p left and @p right subtrees, destroying all child nodes
** before cleaning up the parent node itself.
**
** @param[in, out] node Pointer to the root binary node of the tree to destroy.
** @param[in] free_data Function pointer to free the stored generic data of
** each node. If NULL, the data stored inside the nodes will not be freed.
**
** @return @b void
**/
void destroy_bnode_recursive(bnode_t *node, void (*free_data)(void *));

#endif /* !DKZ_NODE_H_ */
