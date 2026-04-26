/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** file
*/

#ifndef DKZ_FILE_H_
    #define DKZ_FILE_H_

int open_file(char const *filename);

long get_file_size(char const *filename);
long get_file_size_dyn(char const *filename);

char *get_file_content(int fd, long size);

char *read_file(char const *filename);
char *read_file_dyn(char const *filename);

#endif /* !DKZ_FILE_H_ */
