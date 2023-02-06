/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <stdio.h>
#include <string.h>

void int_to_binary_string(int num, char *str)
{
    int i;
    for (i = 2; i >= 0; i -= 1) {
        str[2 - i] = (num & (1 << i)) ? '1' : '0';
    }
    str[3] = '\0';
}
