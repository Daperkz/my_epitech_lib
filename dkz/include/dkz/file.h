/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** file
*/
/**
** @file file.h
** @brief File system interaction and reading utilities.
**
** Functions to handle file descriptors, retrieve file metadata (size),
** and read content into memory via both static and dynamic methods.
**
** @author Daperkz
** @ingroup libdkz
** @test ./test/src/file/
** @version 1.0
** @date 2026-07-05
*/

#ifndef DKZ_FILE_H_
    #define DKZ_FILE_H_

/**
** @brief Opens a file and returns its file descriptor
**
** @param[in] filename The path to the file to open
**
** @return @b int The file descriptor, or -1 if the file cannot be opened
*/
int open_file(char const *filename);

/**
** @brief Gets the size of a file using stat
**
** @param[in] filename The path to the file
**
** @return @b long The size of the file in bytes, or -1 on error
*/
long get_file_size(char const *filename);

/**
** @brief Gets the size of a file by reading it (useful for special files)
**
** @param[in] filename The path to the file
**
** @return @b long The size of the file in bytes, or -1 on error
*/
long get_file_size_dyn(char const *filename);

/**
** @brief Reads a specific number of bytes from a file descriptor
**
** @param[in] fd The file descriptor to read from
** @param[in] size The number of bytes to read
**
** @return @b char* A new allocated string containing the content,
** or NULL on error
*/
char *get_file_content(int fd, long size);

/**
** @brief Reads the entire content of a file into a string using stat
**
** @param[in] filename The path to the file
**
** @return @b char* A new allocated string with file content, or NULL on error
*/
char *read_file(char const *filename);

/**
** @brief Reads the entire content of a file dynamically (without stat)
**
** @param[in] filename The path to the file
**
** @return @b char* A new allocated string with file content, or NULL on error
**
** @note Useful for files where stat fails to report size, like /dev or /proc
*/
char *read_file_dyn(char const *filename);

#endif /* !DKZ_FILE_H_ */
