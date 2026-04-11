/*
** EPITECH PROJECT, 2026
** create.c
** File description:
** create
*/

#include <stdlib.h>

#include "my/file.h"
#include "my/config.h"
#include "my/string.h"

static int process_line(config_t *config, char *line)
{
    char *key = NULL;
    char *value = NULL;

    if (!line)
        return (EXIT_SUCCESS);
    line = my_strtrim(line, WHITESPACES);
    if (*line == '#' || *line == ';' || !(*line))
        return (EXIT_SUCCESS);
    line = my_strtrim(line, WHITESPACES);
    if (!my_strchr(line, '='))
        return (EXIT_SUCCESS);
    key = my_strsep(&line, "=");
    value = my_strdup(line);
    if (!value)
        return (EXIT_FAILURE);
    if (key && value) {
        key = my_strtrim(key, WHITESPACES);
        value = my_strtrim(value, WHITESPACES);
        if (ht_insert(config, key, value) == EXIT_FAILURE)
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

static int parse_file(config_t *config, char *file)
{
    char *work_ptr = file;
    char *line = my_strsep(&work_ptr, "\n");

    while (line) {
        if (process_line(config, line) == EXIT_FAILURE)
            return (EXIT_FAILURE);
        line = my_strsep(&work_ptr, "\n");
    }
    return (EXIT_SUCCESS);
}

config_t *config_create(char const *filepath, int size)
{
    config_t *config = NULL;
    char *file = NULL;

    if (!filepath)
        return (NULL);
    config = ht_create(fnv_1a, size);
    if (!config)
        return (NULL);
    file = read_file(filepath);
    if (!file) {
        ht_destroy(config, NULL);
        return (NULL);
    }
    if (parse_file(config, file) == EXIT_FAILURE) {
        free(file);
        ht_destroy(config, NULL);
        return (NULL);
    }
    free(file);
    return (config);
}
