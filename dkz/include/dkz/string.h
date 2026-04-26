/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** string.h
*/

#ifndef DKZ_STRING_H_
    #define DKZ_STRING_H_

    #define WHITESPACES " \t\r\n"


/* -_- string array -_- */

char **my_str_to_str_arr(char const *str, char const *seps);
long my_len_str_arr(char *const *str_arr);
void my_put_str_arr(char *const *str_arr, char sep);
char **my_cpy_str_arr(char *const *str_arr);
void my_free_str_arr(char **str_arr);

/* -_- convert -_- */

int my_atoi(char const *str);
double my_atof(char const *str);
double my_getfnbrspe(char const *str, int *error_ptr);
int my_getnbrspe(char const *str, int *error_ptr);


/* -_- manipulation -_- */

int my_strlen(char const *str);
int my_strlen_d(char const *str, char delim);
int my_putstr(char const *str);
int my_fputstr(int fd, char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
char *my_strndup(char const *src, int n);
char *my_revstr(char *str);
char *my_strappend(char **dest_ptr, char *src);
char *my_strtrim(char *str, char *seps);

char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);

char *my_strjoin(char const *str1, char const *str2);
void *my_memcpy(void *dest, void const *src, long n);
void *my_memmove(void *dest, void const *src, long n);

/* -_- search -_- */

char *my_strstr(char const *str, char const *to_find);
char *my_strchr(char const *str, char target);
char *my_strrchr(char const *str, char target);
char *my_strsep(char **str_ptr, const char *sep);

/* -_- comparaison -_- */

int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);

#endif /* !DKZ_STRING_H_ */
