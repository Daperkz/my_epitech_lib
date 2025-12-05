/*
** EPITECH PROJECT, 2025
** get_file_size.c
** File description:
** get_file_size
*/

#include <sys/stat.h>
#include <stdio.h>

//returns the size in bytes of said file or -1 in case of error
long get_file_size(const char *filename)
{
    struct stat st;

    if (stat(filename, &st) != 0) {
        perror("Error stat");
        return -1;
    }
    return st.st_size;
}
