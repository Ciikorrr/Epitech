/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/
#include <stdlib.h>
#include <stdio.h>
char my_strcat(char *dest, char *src);
char my_putchar(char c);
int my_strlen(char *c);

char *concat_params(int argc, char **argv)
{
    int taille = 0;
    for (int i = 0; i < argc; i++) {
        taille = taille + my_strlen(argv[i]);
        taille += 1;
    }
    char *str = malloc(taille);
    int idx = 0;
    for (int i = 0; i < argc; i++) {
        my_strcat(str, argv[i]);
        if (i != argc - 1) {
            str[my_strlen(argv[i]) + idx] = '\n';
        } else {
            str[my_strlen(argv[i]) + idx] = '\0';
        }
        idx += my_strlen(argv[i]) + 1;
    }
    return str;
}
