/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** display_arg
*/

#include <stdarg.h>
#include <stdio.h>

void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int i);
int my_strlen(char const *str);

void disp_stdarg(char *s, ...)
{
    va_list list;
    int len = my_strlen(s);
    va_start(list, len);
    for (int i = 0; i < len; i += 1) {
        if (s[i] == 'c') {
            my_putchar(va_arg(list, int));
        }
        if (s[i] == 'i') {
            my_put_nbr(va_arg(list,int));
        }
        if (s[i] == 's') {
            my_putstr(va_arg(list,char const *));
        }
        my_putchar('\n');
    }
    va_end(list);
}
