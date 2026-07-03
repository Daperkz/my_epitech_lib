/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_hash
*/

#include "test.h"

Test(sdbm, null_parameters)
{
    int size = 10;
    char *str = "key";

    cr_assert_eq(sdbm(NULL, size), 0);
    cr_assert_eq(sdbm(str, 0), 0);
    cr_assert_eq(sdbm(str, -10), 0);
}

Test(sdbm, basic)
{
    int size = 10;
    char *str = "key";
    int index = sdbm(str, size);

    cr_assert(index >= 0 && index < size);
}

Test(fnv_1a, null_parameters)
{
    int size = 10;
    char *str = "key";

    cr_assert_eq(fnv_1a(NULL, size), 0);
    cr_assert_eq(fnv_1a(str, 0), 0);
    cr_assert_eq(fnv_1a(str, -10), 0);
}

Test(fnv_1a, basic)
{
    int size = 10;
    char *str = "key";
    int index = fnv_1a(str, size);

    cr_assert(index >= 0 && index < size);
}

Test(djb2, null_parameters)
{
    int size = 10;
    char *str = "key";

    cr_assert_eq(djb2(NULL, size), 0);
    cr_assert_eq(djb2(str, 0), 0);
    cr_assert_eq(djb2(str, -10), 0);
}

Test(djb2, basic)
{
    int size = 10;
    char *str = "key";
    int index = djb2(str, size);

    cr_assert(index >= 0 && index < size);
}

Test(hash, null_parameters)
{
    int size = 10;
    char *str = "key";

    cr_assert_eq(hash(NULL, size), 0);
    cr_assert_eq(hash(str, 0), 0);
    cr_assert_eq(hash(str, -10), 0);
}

Test(hash, basic)
{
    int size = 10;
    char *str = "key";
    int index = hash(str, size);

    cr_assert(index >= 0 && index < size);
}
