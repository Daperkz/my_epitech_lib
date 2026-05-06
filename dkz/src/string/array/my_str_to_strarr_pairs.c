/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** my_str_to_strarr_pairs
*/

#include <stdlib.h>

#include "dkz/string.h"

static int is_seperator(char c, char const *seps)
{
    for (int i = 0; seps[i]; i++) {
        if (c == seps[i])
            return 1;
    }
    return 0;
}

static int skip_seps(char const *str, char const *seps, int *i_ptr)
{
    while (str[*i_ptr] && is_seperator(str[*i_ptr], seps))
        (*i_ptr)++;
    return (*i_ptr);
}

static int find_opener_start(char const *pairs, int i)
{
    int start = i - 1;

    while (start >= 0 && pairs[start] != ';')
        start--;
    return (start + 1);
}

static int check_and_set_closer(
    char const *str, char const *pairs, int *meta, char const **closer_ptr
)
{
    int idx = meta[0];
    int start = find_opener_start(pairs, idx);
    int op_len = idx - start;

    if (my_strncmp(str, &pairs[start], op_len) == 0) {
        *closer_ptr = &pairs[idx + 1];
        meta[1] = 0;
        while ((*closer_ptr)[meta[1]] && (*closer_ptr)[meta[1]] != ';')
            meta[1]++;
        return (op_len);
    }
    return (0);
}

static int match_opening_pair(
    char const *str, char const *pairs, char const **closer_ptr, int *closer_len
)
{
    int meta[2];
    int len;

    if (!pairs || !str)
        return (0);
    for (int i = 0; pairs[i]; i++) {
        if (pairs[i] != ':')
            continue;
        meta[0] = i;
        len = check_and_set_closer(str, pairs, meta, closer_ptr);
        if (len > 0) {
            *closer_len = meta[1];
            return (len);
        }
    }
    return (0);
}

static void handle_pair_skip(
    char const *str, int *i, char const *closer, int len
)
{
    while (str[*i] && my_strncmp(&str[*i], closer, len) != 0)
        (*i)++;
    if (str[*i])
        (*i) += len;
}

static int count_loop_body(
    char const *str, char const *seps, char const *pairs, int *meta
)
{
    char const *closer = NULL;
    int c_len = 0;
    int op_len = match_opening_pair(&str[meta[0]], pairs, &closer, &c_len);

    if (op_len > 0) {
        meta[1] = 1;
        meta[0] += op_len;
        handle_pair_skip(str, &meta[0], closer, c_len);
        return (1);
    }
    if (!is_seperator(str[meta[0]], seps) && !meta[1]) {
        meta[1] = 1;
        meta[0]++;
        return (1);
    }
    if (is_seperator(str[meta[0]], seps))
        meta[1] = 0;
    meta[0]++;
    return (0);
}

static int nbr_words_pairs(char const *str, char const *seps, char const *pairs)
{
    int count = 0;
    int meta[2] = {0, 0};

    while (str[meta[0]]) {
        count += count_loop_body(str, seps, pairs, meta);
    }
    return (count);
}

static char *extract_word_pairs(
    char const *str, char const *seps, char const *pairs, int *i_ptr
)
{
    int start = *i_ptr;
    char const *closer = NULL;
    int c_len = 0;
    int op_len;

    while (str[*i_ptr]) {
        op_len = match_opening_pair(&str[*i_ptr], pairs, &closer, &c_len);
        if (op_len > 0) {
            (*i_ptr) += op_len;
            handle_pair_skip(str, i_ptr, closer, c_len);
            continue;
        }
        if (is_seperator(str[*i_ptr], seps))
            break;
        (*i_ptr)++;
    }
    return (my_strndup(&str[start], *i_ptr - start));
}

char **my_str_to_strarr_pairs(
    char const *str, char const *seps, char const *pairs
)
{
    char **strarr = NULL;
    int wi = 0;

    if (!str || !seps || !pairs || pairs[0] == '\0')
        return ((!str || !seps) ? NULL : my_str_to_strarr(str, seps));
    strarr = malloc(sizeof(char *) * (nbr_words_pairs(str, seps, pairs) + 1));
    if (!strarr)
        return (NULL);
    for (int i = 0; str[i]; wi++) {
        if (!str[skip_seps(str, seps, &i)])
            break;
        strarr[wi] = extract_word_pairs(str, seps, pairs, &i);
        if (!strarr[wi]) {
            my_free_strarr(strarr);
            return (NULL);
        }
    }
    strarr[wi] = NULL;
    return (strarr);
}
