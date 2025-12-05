/*
** EPITECH PROJECT, 2025
** file_utils.h
** File description:
** file_utils
*/

#ifndef FILE_UTILS_H_
    #define FILE_UTILS_H_

int open_file(const char *filename);
long get_file_size(const char *filename);
char *get_file_content(int fd, long size);
char *read_file(const char *filename);

#endif /* !FILE_UTILS_H_ */
