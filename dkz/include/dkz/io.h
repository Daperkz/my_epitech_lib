/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** io.h
*/

#ifndef DKZ_IO_H_
    #define DKZ_IO_H_

int my_putchar(char c);
int my_putchar_fd(int fd, char c);

int my_put_nbr(int nb);
int my_put_nbr_base(int nb, char const *base);

int my_showstr(char const *str);
int my_showmem(char const *str, int size);
int my_show_word_array(char **tab);

#endif /* !DKZ_IO_H_ */
