/*
** EPITECH PROJECT, 2026
** test_config.c
** File description:
** test_config
*/

#include <criterion/criterion.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include "my/config.h"

// Helper to create a dummy config file for testing
void create_test_config(char const *filename, char const *content)
{
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd != -1) {
        write(fd, content, strlen(content));
        close(fd);
    }
}

static void clean_test_basic_conf(void)
{
    remove("test_basic.conf");
}

static void clean_test_noise_conf(void)
{
    remove("test_noise.conf");
}

static void clean_test_garbage_conf(void)
{
    remove("test_garbage.conf");
}

Test(config, basic_parsing, .fini = clean_test_basic_conf)
{
    char const *content = "key=value\nport=8080\npi=3.14\n";
    config_t *conf;

    create_test_config("test_basic.conf", content);
    conf = config_create("test_basic.conf", 10);
    cr_assert_not_null(conf, "Config should not be NULL");
    cr_assert_str_eq(CONFIG_GET(conf, "key"), "value");
    cr_assert_eq(CONFIG_GET_INT(conf, "port"), 8080);
    cr_assert_float_eq(CONFIG_GET_FLOAT(conf, "pi"), 3.14, 0.001);
    CONFIG_DESTROY(conf);
    unlink("test_basic.conf");
}

Test(config, comments_and_empty_lines, .fini = clean_test_noise_conf)
{
    char const *content = (
        "# This is a comment\n\n  \nname=daperkz\n; Another comment\nversion=3"
    );
    config_t *conf = NULL;

    create_test_config("test_noise.conf", content);
    conf = config_create("test_noise.conf", 10);
    cr_assert_not_null(conf);
    cr_assert_str_eq(CONFIG_GET(conf, "name"), "daperkz");
    cr_assert_eq(CONFIG_GET_INT(conf, "version"), 3);
    cr_assert_null(CONFIG_GET(conf, "# This is a comment"));
    CONFIG_DESTROY(conf);
    unlink("test_noise.conf");
}

Test(config, malformed_lines, .fini = clean_test_garbage_conf)
{
    char const *content = "valid=yes\nthis_line_is_garbage\n";
    config_t *conf = NULL;

    create_test_config("test_garbage.conf", content);
    conf = config_create("test_garbage.conf", 5);
    cr_assert_not_null(conf);
    cr_assert_str_eq(CONFIG_GET(conf, "valid"), "yes");
    cr_assert_null(CONFIG_GET(conf, "this_line_is_garbage"));

    CONFIG_DESTROY(conf);
    unlink("test_garbage.conf");
}

Test(config, file_not_found)
{
    config_t *conf = config_create("non_existent_file.conf", 10);
    cr_assert_null(conf, "Should return NULL if file doesn't exist");
}
