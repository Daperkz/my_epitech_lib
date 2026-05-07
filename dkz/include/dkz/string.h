/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** string.h
*/
/**
** @file string.h
** @brief Header file for string manipulation and array utilities.
**
** This file contains the definitions for the libdkz string library,
** including memory management for string arrays and search algorithms.
**
** @author Daperkz
** @ingroup libdkz
** @test ./tests/string/
** @version 1.0
** @date 2026-07-05
*/

#ifndef DKZ_STRING_H_
    #define DKZ_STRING_H_

    #define WHITESPACES " \t\r\n"


/*
** -_-
** STRING ARRAY
** -_-
*/

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

/*
** -_-
** CONVERT
** -_-
*/

/**
** @brief Converts the string to an integer
**
** @param[in] str The string to convert
**
** @return @b int The converted value
**
** @warning The @p str string must only contain numerical characters providing
** other characters will result in undefined or unexpected behavior
*/
int my_atoi(char const *str);

/**
** @brief Converts the initial portion of a string to a double
**
** @param[in] str The string to convert
**
** @return @b double The converted value
**
** @warning The @p str string must only contain numerical characters providing
** other characters will result in undefined or unexpected behavior
*/
double my_atof(char const *str);

/**
** @brief Converts a string to a double with error handling
**
** @param[in] str The string to convert
** @param[in, out] error_ptr Pointer to an int set to 1 on error, 0 on success
**
** @return @b double The converted value
*/
double my_getfnbrspe(char const *str, int *error_ptr);

/**
** @brief Converts a string to a Integer with error handling
**
** @param[in] str The string to convert
** @param[in, out] error_ptr Pointer to an int set to 1 on error, 0 on success
**
** @return @b int The converted value
*/
int my_getnbrspe(char const *str, int *error_ptr);


/*
** -_-
** MANIPULATION
** -_-
*/

/**
** @brief Calculates the length of a string
**
** @param[in] str The '\0'-terminated string
**
** @return @b int The length of the given @p str
** @retval 0 Returned if @p str is NULL or empty.
*/
int my_strlen(char const *str);

/**
** @brief Calculates the length of a string
**
** @param[in] str The '\0'-terminated string
** @param[in] delim A char
**
** @return @b int The length of the given @p str stopping early
** when delim is matched
** @retval 0 Returned if @p str is NULL or empty.
*/
int my_strlen_d(char const *str, char const delim);

/**
** @brief Prints the string into the standard output
**
** @param[in] str The '\0'-terminated string
**
** @return @b int The amount of char printed from @p str
** @retval 0 Returned if @p str is NULL or empty.
** @retval -1 Returned if the Syscall failed.
*/
int my_putstr(char const *str);

/**
** @brief Prints the string into the given @p df
**
** @param[in] fd A file descriptor
** @param[in] str The '\0'-terminated string
**
** @return @b int The amount of char printed from @p str
**
** @retval 0 Returned if @p str is NULL or empty.
** @retval -1 Returned if the Syscall failed or if @p fd is invalid.
*/
int my_fputstr(int fd, char const *str);

/**
** @brief Copies the string @p src to @p dest
**
** @param[out] dest The destination buffer
** @param[in] src The source string
**
** @return @b char* A pointer to the destination string @p dest
*/
char *my_strcpy(char *dest, char const *src);

/**
** @brief Copies up to @p n characters from @p src to @p dest
**
** @param[out] dest The destination buffer
** @param[in] src The source string
** @param[in] n Maximum number of characters to copy
**
** @return @b char* A pointer to the destination string @p dest
**
** @warning Inputting @p n a higher number than @p src contains
** will result in memory errors and probably segfaults
*/
char *my_strncpy(char *dest, char const *src, int n);

/**
** @brief Appends the @p src string to the @p dest string
**
** @param[in, out] dest The destination string
** @param[in] src The source string to append
**
** @return @b char* A pointer to the destination string @p dest
**
** @warning @p dest Needs to contain enough to append @p src otherwise
** will result in memory errors and probably segfaults
*/
char *my_strcat(char *dest, char const *src);

/**
** @brief Appends up to @p nb characters from @p src to @p dest
**
** @param[in, out] dest The destination string
** @param[in] src The source string to append
** @param[in] nb Maximum number of characters to append
**
** @return @b char* A pointer to the destination string @p dest
**
** @warning @p dest Needs to contain enough to append @p src otherwise
** will result in memory errors and probably segfaults
*/
char *my_strncat(char *dest, char const *src, int nb);

/**
** @brief Duplicates a string using dynamic memory allocation
**
** @param[in] src The string to duplicate
**
** @return @b char* The new allocated string, or NULL if allocation fails
*/
char *my_strdup(char const *src);

/**
** @brief Duplicates up to @p n characters of a string
**
** @param[in] src The string to duplicate
** @param[in] n Maximum number of characters to duplicate
**
** @return @b char* The new allocated string, or NULL if allocation fails
**
** @warning @p n can't be higher than @p src can contain otherwise
** will cause memory errors and probably segfaults
*/
char *my_strndup(char const *src, int n);

/**
** @brief Reverses a string in place
**
** @param[in, out] str The string to reverse
**
** @return @b char* A pointer to @p str
*/
char *my_revstr(char *str);

/**
** @brief Concatenates @p src to the end of a dynamically allocated string
**
** @param[in, out] dest_ptr Pointer to the allocated string to extend
** @param[in] src The string to append
**
** @return @b char* The updated pointer @p *dest_ptr, or NULL on failure
*/
char *my_strappend(char **dest_ptr, char *src);

/**
** @brief Removes leading and trailing characters found in @p seps
**
** @param[in, out] str The string to trim
**
** @param[in] seps String containing characters to remove
**
** @return @b char* A pointer to the trimmed string
*/
char *my_strtrim(char *str, char *seps);

/**
** @brief Concatenates @p str1 and @p str2 into a new allocated string
**
** @param[in] str1 First string
** @param[in] str2 Second string
**
** @return @b char* The new allocated string, or NULL on failure
*/
char *my_strjoin(char const *str1, char const *str2);

/**
** @brief Copies @p n bytes from memory area @p src to @p dest
**
** @param[out] dest The destination
** @param[in] src The source
** @param[in] n The size to copy
**
** @return @b void* A pointer to @p dest
*/
void *my_memcpy(void *dest, void const *src, long n);

/**
** @brief Copies @p n bytes from @p src to @p dest (handles overlapping areas)
**
** @param[out] dest The destination
** @param[in] src The source
** @param[in] n The size to copy
**
** @return @b void* A pointer to @p dest
*/
void *my_memmove(void *dest, void const *src, long n);

/**
** @brief Fills the first @p n bytes of memory with constant byte @p c
**
** @param[out] dest The destination
** @param[in] c The source byte
** @param[in] n The size to fill
**
** @return @b void* A pointer to @p dest
*/
void *my_memset(void *dest, int c, long n);

/**
** @brief Converts all alphabetical characters in a string to uppercase
**
** @param[in, out] str The string to modify
**
** @return @b char* A pointer to the modified string @p str
*/
char *my_strupcase(char *str);


/**
** @brief Converts all alphabetical characters in a string to lowercase
**
** @param[in, out] str The string to modify
**
** @return @b char* A pointer to the modified string @p str
*/
char *my_strlowcase(char *str);

/**
** @brief Capitalizes the first letter of each word and lowers the rest
**
** @param[in, out] str The string to modify
**
** @return @b char* A pointer to the modified string @p str
*/
char *my_strcapitalize(char *str);


/*
** -_-
** SEARCH
** -_-
*/

/**
** @brief Locates the first occurrence the pattern in the str
** Boyer-Moore algorithm
** BC : O(N/M)
** WC : O(N + M)
** @return A pointer the located pattern, NULL if pattern was not found.
*/
char *my_strstr(char const *str, char const *to_find);

/**
** @brief Locates the first occurrence of @p target in @p str
**
** @param[in] str The string to parse
** @param[in] target The character to find
**
** @return @b char* Pointer to the match, or NULL if not found
*/
char *my_strchr(char const *str, char target);

/**
** @brief Locates the last occurrence of @p target in @p str
**
** @param[in] str The string to parse
** @param[in] target The character to find
**
** @return @b char* Pointer to the match, or NULL if not found
*/
char *my_strrchr(char const *str, char target);

/**
** @brief Extracts a token from a string using @p sep as delimiter
**
** @param[in, out] str_ptr Pointer to the string to parse
** @param[in] sep Delimiter string
**
** @return @b char* Pointer to the token
*/
char *my_strsep(char **str_ptr, const char *sep);

/*
** -_-
** COMPARAISON
** -_-
*/

/**
** @brief Compares two strings
**
** @param[in] s1 The first string
** @param[in] s2 The second string
**
** @return @b int : 0 if equal, <0 if s1 < s2, >0 if s1 > s2
*/
int my_strcmp(char const *s1, char const *s2);

/**
** @brief Compares up to @p n characters of two strings
**
** @param[in] s1 The first string
** @param[in] s2 The second string
**
** @return @b int : 0 if equal, <0 if s1 < s2, >0 if s1 > s2
*/
int my_strncmp(char const *s1, char const *s2, int n);

/**
** @brief Checks if the string contains only alphabetical characters
**
** @param[in] str The String to check
**
** @return @b int 1 if true, 0 otherwise
*/
int my_str_isalpha(char const *str);


/**
** @brief Checks if the string contains only numeric characters
**
** @param[in] str The String to check
**
** @return @b int 1 if true, 0 otherwise
*/
int my_str_isnum(char const *str);


/**
** @brief Checks if the string contains lowercase alphabetical characters
**
** @param[in] str The String to check
**
** @return @b int 1 if true, 0 otherwise
*/
int my_str_islower(char const *str);

/**
** @brief Checks if the string contains uppercase alphabetical characters
**
** @param[in] str The String to check
**
** @return @b int 1 if true, 0 otherwise
*/
int my_str_isupper(char const *str);

/**
** @brief Checks if the string contains only printable characters
**
** @param[in] str The String to check
**
** @return @b int 1 if true, 0 otherwise
*/
int my_str_isprintable(char const *str);

#endif /* !DKZ_STRING_H_ */
