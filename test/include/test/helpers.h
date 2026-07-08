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

#endif /* !LIBDKZ_TEST_HELPERS_H_ */
