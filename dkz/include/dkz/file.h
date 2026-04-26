/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** file
*/

#ifndef DKZ_FILE_H_
    #define DKZ_FILE_H_

int open_file(const char *filename);

long get_file_size(const char *filename);
long get_file_size_dyn(const char *filename);

char *get_file_content(int fd, long size);

char *read_file(const char *filename);
char *read_file_dyn(const char *filename);

#endif /* !DKZ_FILE_H_ */
