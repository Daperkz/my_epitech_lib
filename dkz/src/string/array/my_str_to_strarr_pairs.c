/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** my_str_to_strarr_pairs
*/

#include <stdlib.h>
#include "dkz/string.h"

struct token_s {
    int start;
    int end;
    int next;
};

static int get_pat_len(char const *pattern, int is_open)
{
    int len = 0;
    char stop = is_open ? ':' : ';';

    while (pattern[len] && pattern[len] != stop)
        len++;
    return len;
}

static int match_bracket_side(
    char const *str, char const *pairs, int is_open, int *pair_id
)
{
    int s;
    int len;
    char const *pat;

    for (int i = 0; pairs && pairs[i]; i++) {
        if (pairs[i] != ':')
            continue;
        s = i - 1;
        while (s >= 0 && pairs[s] != ';')
            s--;
        pat = is_open ? &pairs[s + 1] : &pairs[i + 1];
        len = get_pat_len(pat, is_open);
        if (my_strncmp(str, pat, len) == 0) {
            *pair_id = i;
            return len;
        }
    }
    return 0;
}

static int handle_pair_match(
    int closelen, int dest_id, int curr_id, int *depth
)
{
    if (closelen > 0 && curr_id == dest_id) {
        *depth -= 1;
        if (*depth == 0)
            return 1;
    }
    return 0;
}

static int pair_loop(
    char const *str, char const *pairs, int dest_id, struct token_s *token
)
{
    int closelen;
    int openlen;
    int curr_id;
    int depth = 1;

    for (int i = token->start; str[i]; i++) {
        closelen = match_bracket_side(&str[i], pairs, 0, &curr_id);
        if (handle_pair_match(closelen, dest_id, curr_id, &depth)) {
            token->end = i;
            token->next = i + closelen;
            return 1;
        }
        openlen = match_bracket_side(&str[i], pairs, 1, &curr_id);
        if (openlen > 0 && curr_id == dest_id) {
            depth++;
            i += openlen - 1;
        }
    }
    return -1;
}

static int find_simple_token(char const *str, char const *seps,
    char const *pairs, struct token_s *token)
{
    int i = token->start;
    int curr_id;

    while (str[i] && !my_strchr(seps, str[i]) &&
        !match_bracket_side(&str[i], pairs, 1, &curr_id))
        i++;
    token->end = i;
    token->next = i;
    return 1;
}

static int get_bounds(char const *str, char const *seps, char const *pairs,
    struct token_s *token)
{
    int i = token->next;
    int openlen;
    int dest_id;

    while (str[i] && my_strchr(seps, str[i]))
        i++;
    if (!str[i])
        return 0;
    openlen = match_bracket_side(&str[i], pairs, 1, &dest_id);
    if (openlen > 0) {
        token->start = i + openlen;
        return pair_loop(str, pairs, dest_id, token);
    }
    token->start = i;
    return find_simple_token(str, seps, pairs, token);
}

static int count_tokens(char const *str, char const *seps, char const *pairs)
{
    int n = 0;
    int stat = 1;
    struct token_s t = {0, 0, 0};

    while (stat > 0) {
        stat = get_bounds(str, seps, pairs, &t);
        if (stat > 0)
            n++;
    }
    return (stat == -1) ? -1 : n;
}

char **my_str_to_strarr_pairs(char const *str, char const *seps,
    char const *pairs)
{
    int n;
    char **arr;
    struct token_s t = {0, 0, 0};

    if (!str || !seps || !pairs || !*pairs)
        return (!str || !seps) ? (NULL) : (my_str_to_strarr(str, seps));
    n = count_tokens(str, seps, pairs);
    if (n < 0)
        return (NULL);
    arr = malloc(sizeof(char *) * (n + 1));
    if (!arr)
        return (NULL);
    for (int i = 0; i < n; i++) {
        get_bounds(str, seps, pairs, &t);
        arr[i] = my_strndup(&str[t.start], t.end - t.start);
    }
    arr[n] = NULL;
    return (arr);
}
