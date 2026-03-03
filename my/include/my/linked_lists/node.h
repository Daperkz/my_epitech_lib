/*
** EPITECH PROJECT, 2026
** node.h
** File description:
** node
*/

#ifndef NODE_H_
    #define NODE_H_


typedef struct node_s {
    void *data;
    struct node_s *next;
} node_t;


typedef struct dnode_s {
    void *data;
    struct dnode_s *prev;
    struct dnode_s *next;
} dnode_t;

#endif /* !NODE_H_ */
