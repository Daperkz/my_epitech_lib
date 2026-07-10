/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_parser
*/

#include "test.h"

Test(handle_conversion, basic_parsing_digits, .init = cr_redirect_stdout)
{
    pf_ctx_t ctx = {.fd = 1, .count = 0, .error = 0};
    char *out_str = NULL;
    int offset;

    offset = handle_conversion_wrapper(&ctx, "5.3d", &out_str, NULL);
    cr_assert_gt(offset, 0);
    cr_assert_eq(ctx.error, 0);
}

Test(handle_conversion, flags_accumulation, .init = cr_redirect_stdout)
{
    pf_ctx_t ctx = {.fd = 1, .count = 0, .error = 0};
    char *out_str = NULL;
    int offset;

    offset = handle_conversion_wrapper(&ctx, "-+ #02d", &out_str, NULL);
    cr_assert_gt(offset, 0);
    cr_assert_eq(ctx.error, 0);
}

Test(handle_conversion, dynamic_width_and_precision, .init = cr_redirect_stdout)
{
    pf_ctx_t ctx = {.fd = 1, .count = 0, .error = 0};
    char *out_str = NULL;
    hcv_args_t args = {.width = 10, .precision = 5};
    int offset;

    offset = handle_conversion_wrapper(&ctx, "*.*d", &out_str, &args);
    cr_assert_gt(offset, 0);
    cr_assert_eq(ctx.error, 0);
    cr_assert_eq(ctx.count, 10);
}

Test(handle_conversion, unknown_specifier, .init = cr_redirect_stdout)
{
    pf_ctx_t ctx = {.fd = 1, .count = 0, .error = 0};
    char *out_str = NULL;
    int offset = handle_conversion_wrapper(&ctx, "Z", &out_str, NULL);

    cr_assert_eq(offset, 0);
    cr_assert_stdout_eq_str("");
}

Test(handle_conversion, write_to_buffer_sprintf)
{
    pf_ctx_t ctx = {.fd = -1, .count = 0, .error = 0};
    char *out_str = strdup("");
    int offset;

    cr_assert_not_null(out_str);
    offset = handle_conversion_wrapper(&ctx, "d", &out_str, NULL);
    cr_assert_gt(offset, 0);
    cr_assert_not_null(out_str);
    free(out_str);
}

Test(
    handle_conversion, fd_write_failure,
    .init = cr_redirect_stdout, .fini = reset_write_wrapper
)
{
    pf_ctx_t ctx = {.fd = 1, .count = 0, .error = 0};
    char *out_str = NULL;
    int offset;

    set_write_fail(1);
    set_write_count(0);
    offset = handle_conversion_wrapper(&ctx, "d", &out_str, NULL);
    cr_assert_eq(offset, -1);
    cr_assert_eq(ctx.error, 1);
    cr_assert_stdout_eq_str("");
}

Test(handle_conversion, dynamic_width_only, .init = cr_redirect_stdout)
{
    pf_ctx_t ctx = {.fd = 1, .count = 0, .error = 0};
    char *out_str = NULL;
    hcv_args_t args = {.width = 8, .precision = -1};
    int offset = handle_conversion_wrapper(&ctx, "*d", &out_str, &args);

    cr_assert_gt(offset, 0);
    cr_assert_eq(ctx.count, 8);
}

Test(handle_conversion, dynamic_precision_only, .init = cr_redirect_stdout)
{
    pf_ctx_t ctx = {.fd = 1, .count = 0, .error = 0};
    char *out_str = NULL;
    hcv_args_t args = {.width = 0, .precision = 4};
    int offset = handle_conversion_wrapper(&ctx, ".*d", &out_str, &args);

    cr_assert_gt(offset, 0);
}

Test(handle_conversion, left_flag_coverage, .init = cr_redirect_stdout)
{
    pf_ctx_t ctx = {.fd = 1, .count = 0, .error = 0};
    char *out_str = NULL;
    int offset = handle_conversion_wrapper(&ctx, "-d", &out_str, NULL);

    cr_assert_gt(offset, 0);
    cr_assert_stdout_eq_str("0");
}

Test(handle_conversion, space_and_sharp_flags, .init = cr_redirect_stdout)
{
    pf_ctx_t ctx = {.fd = 1, .count = 0, .error = 0};
    char *out_str = NULL;
    int offset = handle_conversion_wrapper(&ctx, "# d", &out_str, NULL);

    cr_assert_gt(offset, 0);
    cr_assert_stdout_eq_str(" 0");
}

Test(
    handle_conversion, strappend_malloc_failure,
    .init = cr_redirect_stdout, .fini = reset_malloc_wrapper
)
{
    pf_ctx_t ctx = {.fd = -1, .count = 0, .error = 0};
    char *out_str = strdup("");
    int offset;

    set_malloc_fail(1);
    set_malloc_count(1);
    offset = handle_conversion_wrapper(&ctx, "d", &out_str, NULL);
    cr_assert_eq(offset, -1);
    free(out_str);
    cr_assert_stdout_eq_str("");
}

Test(
    handle_conversion, parameter_callback_returns_null,
    .init = cr_redirect_stdout, .fini = reset_malloc_wrapper
)
{
    pf_ctx_t ctx = {.fd = 1, .count = 0, .error = 0};
    char *out_str = NULL;
    int offset;

    set_malloc_fail(1);
    set_malloc_count(0);
    offset = handle_conversion_wrapper(&ctx, "%", &out_str, NULL);
    cr_assert_eq(offset, -1);
    cr_assert_stdout_eq_str("");
}

Test(
    handle_conversion, dynamic_width_only_force_stack,
    .init = cr_redirect_stdout
)
{
    pf_ctx_t ctx = {.fd = 1, .count = 0, .error = 0};
    char *out_str = NULL;
    hcv_args_t args = {.width = 8, .precision = -1};
    int offset = handle_conversion_wrapper_force_stack(
        &ctx, "*d", &out_str, &args
    );

    cr_assert_gt(offset, 0);
    cr_assert_eq(ctx.count, 8);
}

Test(
    handle_conversion, dynamic_precision_only_force_stack,
    .init = cr_redirect_stdout
)
{
    pf_ctx_t ctx = {.fd = 1, .count = 0, .error = 0};
    char *out_str = NULL;
    hcv_args_t args = {.width = 0, .precision = 4};
    int offset = handle_conversion_wrapper_force_stack(
        &ctx, ".*d", &out_str, &args
    );

    cr_assert_gt(offset, 0);
}

Test(handle_conversion, empty_format_string, .init = cr_redirect_stdout)
{
    pf_ctx_t ctx = {.fd = 1, .count = 0, .error = 0};
    char *out_str = NULL;
    int offset;

    offset = handle_conversion_wrapper(&ctx, "", &out_str, NULL);
    cr_assert_eq(offset, 0);
    cr_assert_stdout_eq_str("");
}
