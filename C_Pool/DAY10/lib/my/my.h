/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb, int i);
int my_find_prime_sup(int nb);
int my_is_prime(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
void my_putchar(char c);
int my_put_nbr(int nb);
void my_putstr(char const *str);
char *my_revstr(char *str);
char *my_showmem(char const *str, int size);
char *my_showstr(char const *str);
void my_sort_int_array(int *array, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_str_isalpha(char const *str);
char *my_str_islower(char const *str);
char my_str_isnum(char const *str);
char *my_str_isprintable(char const *str);
char *my_str_isuppere(char const *str);
int my_strlen(char c);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);

#endif MY_H
