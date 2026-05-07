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

/**
** @brief Splits a string into an array of words
**
** @param[in] str The target string to be split into an array.
** @param[in] seps A string containing all chars to treat as word boundaries.
**
** @return @b char** An allocated, NULL-terminated array of strings
** representing the extracted tokens.
** @retval NULL Returned if @p str or @p seps is NULL, or if a memory allocation
** failure occurs during runtime.
**
** @note Example:
** my_str_to_strarr("Hello (World ) -|complex text|-", " \t\n")
** -> {"Hello", "(World", ")", "-|complex", "text|-"}
*/
char **my_str_to_strarr(char const *str, char const *seps);

/**
** @brief Splits a string into an array of words, ignoring separators when
** they are enclosed within specified boundary pairs (e.g., quotes, brackets).
**
** @param[in] str The target string to be split into an array.
** @param[in] seps A string containing all chars to treat as word boundaries.
** @param[in] pairs A configuration string defining multi-character boundary
** rules, formatted as "open:close" and separated by semicolons (e.g., "\":\"").
**
** @return @b char** An allocated, NULL-terminated array of strings
** representing the extracted tokens.
** @retval NULL Returned if @p str or @p seps is NULL, or if a memory allocation
** failure occurs during runtime.
**
** @note If @p pairs is NULL or empty, the function automatically falls back to
** the standard behavior of @ref my_str_to_strarr.
**
** @warning The @p pairs string must follow the "open:close;" format strictly.
** Providing empty patterns (e.g., "::") or missing delimiters (':' or ';')
** will result in undefined or unexpected behavior, including potential 
** infinite loops or incorrect tokenization.
**
** my_str_to_strarr_pairs("Hello (World ) -|complex text|-",
** " \t\n", "(:);-|:|-")
** -> {"Hello", "World ", "complex text"}
*/
char **my_str_to_strarr_pairs(
    char const *str, char const *seps, char const *pairs
);

/**
** @brief Calculates the length of a string array
**
** @param[in] strarr The NULL-terminated string array
**
** @return @b int The length of the given @p strarr
** @retval 0 Returned if @p strarr is NULL or empty.
*/
long my_len_strarr(char *const *strarr);

/**
** @brief Prints the string array to the standard output
**
** @param[in] strarr The NULL-terminated string array
** @param[in] sep A simple char which is printed between each string of strarr
**
** @return @b void
*/
void my_put_strarr(char *const *strarr, char sep);

/**
** @brief Copies the given @p strarr
**
** @param[in] strarr an allocated NULL-terminated array of strings
**
** @return @b char** An allocated, NULL-terminated array of strings
** a copy of @p strarr.
** @retval NULL Returned if @p strarr is NULL, or if a memory allocation failure
** occurs during runtime.
*/
char **my_cpy_strarr(char *const *strarr);

/**
** @brief frees the memory of the given @p strarr
**
** @param[in, out] strarr an allocated NULL-terminated array of strings
**
** @return @b void
*/
void my_free_strarr(char **strarr);

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
void *my_memset(void *dest, int c, long n);

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
