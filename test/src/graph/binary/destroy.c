/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** destroy
*/

#include "test.h"

Test(btree_destroy, null_entry)
{
    btree_destroy(NULL, NULL);
}
