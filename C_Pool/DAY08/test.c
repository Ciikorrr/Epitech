/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include <stdlib.h>
#include <stdio.h>

char *my_strcpy(char *dest, char *src);

int my_alpha(char c)
{
    if ((c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '1' && c <= '9')) {
        return 1;
    }
    return 0;
}

char **add(char *str, int index,int nb_word)
{
    int taille = 0;
    for (int i = index; my_alpha(str[index]) == 1; i += 1) {
        taille += 1;
    }
    char **tab = malloc(sizeof(char *) * (nb_word + 1));
    int j = 0;
    for (int a = 0; a < taille; a += 1) {
        my_strcpy(tab[j][a], str[a]);
    }
    j += 1;
    return tab;
}

int main(void)
{
    printf("%s", add(("Marius"), 0,1));
}
