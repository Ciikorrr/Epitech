/*
** EPITECH PROJECT, 2022
** my_strlen_index
** File description:
** my_strlen_index
*/
#include <stdio.h>
int my_alpha(char c);

int my_strlen_index(char *str, int index)
{
    int lenght = 0;
    int i = index;
    for (i; str[i] != '\0' && my_alpha(str[i]) == 1; i += 1) {
            lenght += 1;
    }
    return lenght;
}
