/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdio.h>
#include <stdlib.h>
int my_compute_power_rec(int nb, int p);
int my_strlen(char const *str);

char *my_revstr_bis(char *str)
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

int bin_to_dec(char *str)
{
    int decimal = 0;
    str = my_revstr_bis(str);
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '1') {
            decimal = decimal + my_compute_power_rec(2, i);
        }
    }
    return decimal;
}
