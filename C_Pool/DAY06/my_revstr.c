/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** reverse str
*/
#include <stdlib.h>
int my_strlen(char const *str);

char *my_revstr(char *str)
{
    char *reversed = malloc(sizeof(my_strlen(str)));
    int i = (my_strlen(str) - 1);
    int a = 0;
    while (i != -1) {
        reversed[a] = str[i];
        a += 1;
        i -= 1;
    }
    return reversed;
}
