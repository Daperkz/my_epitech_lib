/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_printf
*/

#include "test.h"

// ==========================================================================
// 1. my_printf Tests (STDOUT)
// ==========================================================================

Test(my_printf, basic_string_no_format, .init = cr_redirect_stdout)
{
    int ret = my_printf("Hello World!");

    cr_assert_eq(ret, 12);
    cr_assert_stdout_eq_str("Hello World!");
}

Test(my_printf, null_format)
{
    int ret = my_printf(NULL);

    cr_assert_eq(ret, -1);
}

Test(my_printf, pure_string_no_specifiers, .init = cr_redirect_stdout)
{
    int ret = my_printf("Hello World");

    cr_assert_eq(ret, 11);
    cr_assert_stdout_eq_str("Hello World");
}

Test(my_printf, pure_string_write_fault,
    .init = cr_redirect_stdout, .fini = reset_write_wrapper)
{
    int ret;

    set_write_fail(1);
    set_write_count(0);
    ret = my_printf("Hello World");
    cr_assert_eq(ret, -1);
    cr_assert_stdout_eq_str("");
}

Test(my_printf, trailing_percent_error, .init = cr_redirect_stdout)
{
    int ret = my_printf("Hello %");

    cr_assert_eq(ret, -1);
    cr_assert_stdout_eq_str("Hello ");
}

Test(my_printf, mixed_string_write_fault,
    .init = cr_redirect_stdout, .fini = reset_write_wrapper)
{
    int ret;
    set_write_fail(1);
    set_write_count(0);
    ret = my_printf("Pre-format text %d", 42);
    cr_assert_eq(ret, -1);
    cr_assert_stdout_eq_str("");
}

// ==========================================================================
// 2. my_fprintf Tests (File Descriptors)
// ==========================================================================

Test(my_fprintf, write_to_stdout, .init = cr_redirect_stdout)
{
    int ret = my_fprintf(1, "Testing fprintf on stdout");

    cr_assert_eq(ret, 25);
    cr_assert_stdout_eq_str("Testing fprintf on stdout");
}

Test(my_fprintf, null_format)
{
    int ret;

    ret = my_fprintf(1, NULL);
    cr_assert_eq(ret, -1);
    ret = my_fprintf(-1, "test");
    cr_assert_eq(ret, -1);
}

Test(my_fprintf, pure_string_success, .init = cr_redirect_stdout)
{
    int ret = my_fprintf(1, "No percent tags here");

    cr_assert_eq(ret, 20);
    cr_assert_stdout_eq_str("No percent tags here");
}


// ==========================================================================
// 3. my_sprintf Tests (String Buffers)
// ==========================================================================

Test(my_sprintf, basic_append_to_null)
{
    char *str = NULL;
    int ret = my_sprintf(&str, "Hello %d", 42);

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "Hello 42");
    cr_assert_eq(ret, 8);
    free(str);
}

Test(my_sprintf, append_to_existing_string)
{
    char *str = strdup("Existing: ");
    int ret;

    cr_assert_not_null(str);
    ret = my_sprintf(&str, "Added text");
    cr_assert_str_eq(str, "Existing: Added text");
    cr_assert_eq(ret, 10);
    free(str);
}

Test(my_sprintf, null_double_pointer)
{
    int ret = my_sprintf(NULL, "This should fail safely");

    cr_assert_eq(ret, -1);
}

Test(my_sprintf, initial_allocation_fail, .fini = reset_malloc_wrapper)
{
    char *str = NULL;
    int ret;

    set_malloc_fail(1);
    set_malloc_count(0);
    ret = my_sprintf(&str, "test");
    cr_assert_eq(ret, -1);
}

Test(my_sprintf, append_allocation_fail, .fini = reset_malloc_wrapper)
{
    char *str = NULL;
    int ret;

    set_malloc_fail(1);
    set_malloc_count(1);
    ret = my_sprintf(&str, "test");
    cr_assert_eq(ret, -1);
    free(str);
}

Test(my_sprintf, conversion_crash, .fini = reset_malloc_wrapper)
{
    char *str = NULL;
    int ret;

    set_malloc_fail(1);
    set_malloc_count(1);
    ret = my_sprintf(&str, "%");
    cr_assert_eq(ret, -1);
    cr_assert_null(str);
}

Test(
    my_sprintf, given_allocated_string_conversion_crash
)
{
    char *str = strdup("Hello");
    int ret;

    cr_assert_not_null(str);
    ret = my_sprintf(&str, "%");
    cr_assert_eq(ret, -1);
    cr_assert_not_null(str);
}

Test(my_sprintf, external_str_error_path, .init = cr_redirect_stdout)
{
    char *str = strdup("Existing");
    int ret = my_sprintf(&str, "Invalid %");

    cr_assert_eq(ret, -1);
    cr_assert_not_null(str);
    cr_assert_stdout_eq_str("");
    free(str);
}

// ==========================================================================
// 4. Edge Cases & Error Handling
// ==========================================================================

Test(my_printf, percentage_escapes, .init = cr_redirect_stdout)
{
    int ret = my_printf("Escaping test: %%");

    cr_assert_gt(ret, 0);
    cr_assert_stdout_eq_str("Escaping test: %");
}

Test(my_sprintf, malloc_failure, .fini = reset_malloc_wrapper)
{
    char *str = NULL;
    int ret;

    set_malloc_fail(1);
    set_malloc_count(0);
    ret = my_sprintf(&str, "Boom");
    cr_assert_eq(ret, -1);
    cr_assert_null(str);
}
