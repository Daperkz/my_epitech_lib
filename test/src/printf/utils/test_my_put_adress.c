/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_put_adress
*/

#include "test.h"

Test(my_put_adress, null_entry)
{
    char *result = my_put_adress(NULL);

    cr_assert_not_null(result);
    cr_assert_str_eq(result, "(nil)", "Should return (nil) for NULL input");
    free(result);
}

Test(my_put_adress, valid_address)
{
    int dummy = 42;
    void *ptr = &dummy;
    char *result = my_put_adress(ptr);

    cr_assert_not_null(result, "Result should not be NULL for valid pointer");
    cr_assert(result[0] == '0' && result[1] == 'x', "Should start with 0x");
    free(result);
}

Test(my_put_adress, verify_hex_content)
{
    void *ptr = (void *)0xDEADBEEF;
    char *result = my_put_adress(ptr);

    cr_assert_not_null(result);
    cr_assert_str_eq(
        result, "0xdeadbeef", "Should correctly convert address to hex"
    );
    free(result);
}

Test(my_put_adress, first_malloc_failure, .fini = reset_malloc_wrapper)
{
    void *ptr = (void *)0xDEADBEEF;
    char *result;

    set_malloc_fail(1);
    set_malloc_count(0);
    result = my_put_adress(ptr);
    cr_assert_null(result);
}

Test(my_put_adress, second_malloc_failure, .fini = reset_malloc_wrapper)
{
    void *ptr = (void *)0xDEADBEEF;
    char *result;

    set_malloc_fail(1);
    set_malloc_count(1);
    result = my_put_adress(ptr);
    cr_assert_null(result);
}
