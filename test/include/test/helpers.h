/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** helpers
*/

#ifndef LIBDKZ_TEST_HELPERS_H_
    #define LIBDKZ_TEST_HELPERS_H_

void create_test_file(const char *name, const char *content);


char *parameter_wrapper(
    pf_ctx_t *c, char *(*parameter_func)(va_list, pf_ctx_t *), ...
);
char *parameter_wrapper_stack_forced(
    pf_ctx_t *c, char *(*parameter_func)(va_list, pf_ctx_t *),
    const char *type, void *val
);


typedef struct hcv_args_s {
    int width;
    int precision;
} hcv_args_t;


int handle_conversion_wrapper(
    pf_ctx_t *ctx, const char *format, char **str_ptr, struct hcv_args_s *args
);

int handle_conversion_wrapper_force_stack(
    pf_ctx_t *ctx, const char *format, char **str_ptr, struct hcv_args_s *args
);

#endif /* !LIBDKZ_TEST_HELPERS_H_ */
