/*
** EPITECH PROJECT, 2025
** string_utils.h
** File description:
** string_utils
*/

#ifndef STRING_UTILS_H_
    #define STRING_UTILS_H_

int my_putstr(char const *str);
int my_putstr_fd(int fd, char const *str);

int my_strlen(char const *str);
int my_strlen_d(char const *str, char delim);

int my_getnbr(char const *str);
double my_getfnbr(char *str);
double my_getfnbrspe(char *str, int *error_ptr);
int my_getnbrspe(char *str, int *error_ptr);

char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);

int my_strstr(char *str, char const *to_find);

int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);

char *my_strdup(char const *src);
char *my_strndup(char const *src, int n);

char **my_str_to_word_array(char const *str);
char *my_strappend(char **dest_ptr, char *src);

#endif /* !STRING_UTILS_H_ */
