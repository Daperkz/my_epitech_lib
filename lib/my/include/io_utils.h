/*
** EPITECH PROJECT, 2025
** io_utils.h
** File description:
** io_utils
*/

#ifndef IO_UTILS_H_
    #define IO_UTILS_H_

int my_putchar(char c);
int my_putchar_fd(int fd, char c);

int my_put_nbr(int nb);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
int my_show_word_array(char **tab);

#endif /* !IO_UTILS_H_ */
