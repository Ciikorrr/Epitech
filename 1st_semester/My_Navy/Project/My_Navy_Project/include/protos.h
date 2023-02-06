/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include "protos_struct.h"

#ifndef PROTOS_H_
    #define PROTOS_H_

int my_compute_power_rec(int nb, int p);
char *my_slice(char *str, char *slice);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_putstring_base(int nb, char const *base);
char *my_strcat(char *dest, char const *src);
int my_getnbr(char *str);
int my_printf(char const *format, ...);
int my_put_nbr(int nb);
char *file_to_str(char const *filepath);
void display_desc(void);
int do_error_handling(int argc, char **argv);
char *strcat_bis(char *str1, char *str2);
int bin_to_dec(char *str);
void int_to_binary_string(int num, char *str);

#endif /* !PROTOS_H_*/
