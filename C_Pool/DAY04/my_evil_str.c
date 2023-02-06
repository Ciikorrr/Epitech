/*
** EPITECH PROJECT, 2022
** my_evil_str
** File description:
** reverse a word
*/
#include <stdlib.h>

char *my_evil_str(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    char *reversed = malloc(sizeof(char) * i);
    int a = 0;
    while (i != -1) {
        reversed[a] = str[i];
        a += 1;
        i -= 1;
    }
    return reversed;
}
