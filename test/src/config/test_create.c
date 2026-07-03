/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_config
*/

#include "test.h"

void create_file(char const *filename, char const *content)
{
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd != -1) {
        write(fd, content, strlen(content));
        close(fd);
    }
}

static void remove_file(char const **filename)
{
    if (filename && *filename)
        remove(*filename);
}

Test(config_create, null_parameters)
{
    cr_assert_null(config_create(NULL, 10));
    cr_assert_null(config_create("test_basic", 0));
}

Test(config_create, basic_parsing)
{
    char const *filename
        __attribute__((cleanup(remove_file))) = "test_basic.conf";
    char const *content = "key=value\nport=8080\npi=3.14\n";
    config_t *conf;

    create_file(filename, content);
    conf = config_create(filename, 10);
    cr_assert_not_null(conf, "Config should not be NULL");
    cr_assert_str_eq(CONFIG_GET(conf, "key"), "value");
    cr_assert_eq(CONFIG_GET_INT(conf, "port"), 8080);
    cr_assert_float_eq(CONFIG_GET_FLOAT(conf, "pi"), 3.14, 0.001);
    CONFIG_DESTROY(conf);
}

Test(config_create, comments_and_empty_lines)
{
    char const *filename
        __attribute__((cleanup(remove_file))) = "test_noise.conf";
    char const *content = (
        "# This is a comment\n\n  \nname=daperkz\n; Another comment\nversion=3"
    );
    config_t *conf = NULL;

    create_file(filename, content);
    conf = config_create(filename, 10);
    cr_assert_not_null(conf);
    cr_assert_str_eq(CONFIG_GET(conf, "name"), "daperkz");
    cr_assert_eq(CONFIG_GET_INT(conf, "version"), 3);
    cr_assert_null(CONFIG_GET(conf, "# This is a comment"));
    CONFIG_DESTROY(conf);
}

Test(config_create, malformed_lines)
{
    char const *filename
        __attribute__((cleanup(remove_file))) = "test_garbage.conf";
    char const *content = "valid=yes\nthis_line_is_garbage\n";
    config_t *conf = NULL;

    create_file(filename, content);
    conf = config_create(filename, 5);
    cr_assert_not_null(conf);
    cr_assert_str_eq(CONFIG_GET(conf, "valid"), "yes");
    cr_assert_null(CONFIG_GET(conf, "this_line_is_garbage"));
    CONFIG_DESTROY(conf);
}

Test(config_create, file_not_found)
{
    config_t *conf = config_create("non_existent_file.conf", 10);

    cr_assert_null(conf, "Should return NULL if file doesn't exist");
}

Test(config_create, strdup_failure, .fini = reset_malloc_wrapper)
{
    char const *filename
        __attribute__((cleanup(remove_file))) = "test_dup.conf";
    config_t *config = NULL;

    create_file(filename, "key=value");
    set_malloc_fail(1);
    set_malloc_count(3);
    config = config_create(filename, 10);
    cr_assert_null(config);
}

Test(config_create, config_insertion_fails, .fini = reset_malloc_wrapper)
{
    char const *filename
        __attribute__((cleanup(remove_file))) = "test_insert.conf";
    config_t *config = NULL;

    create_file(filename, "key=value");
    set_malloc_fail(1);
    set_malloc_count(4);
    config = config_create(filename, 10);
    cr_assert_null(config);
}
