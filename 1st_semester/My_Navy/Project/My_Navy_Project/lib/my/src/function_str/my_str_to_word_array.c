/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** ouais
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int my_show_word_array(char * const tab[]);

int my_isalpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
        || (c >= '0' && c <= '9'))  {
        return (1);
    }
    return (0);
}

int word_nbr(const char *str)
{
    int i = 0;
    int nbr_mot = 0;
    while (my_isalpha(str[i]) != 1) {
        i = i + 1;
    }
    for (i; str[i] != '\0'; i = i + 1) {
        if (my_isalpha(str[i]) == 0 && my_isalpha(str[i + 1]) == 1) {
            nbr_mot = nbr_mot + 1;
        }
    }
    return (nbr_mot);
}

char *get_word(char *tab, const char *str, int i)
{
    int len = 0;
    int index = i;
    while (my_isalpha(str[i]) == 1) {
        len = len + 1;
        i = i + 1;
    }
    tab = malloc(sizeof(char) * (len));
    for (int j = 0; j < len; j = j + 1) {
        tab[j] = str[index];
        index = index + 1;
    }
    return (tab);
}

int getindex(int index, const char *str)
{
    int nbr = 0;
    int i = 0;
    while (my_isalpha(str[i]) != 1) {
        i = i + 1;
    }
    while (str[i] != '\0') {
        if (nbr == index) {
            return (i);
        }
        if (my_isalpha(str[i]) == 0 && my_isalpha(str[i + 1]) == 1) {
            nbr = nbr + 1;
        }
        i = i + 1;
    }
    return (i);
}

char **my_str_to_word_array(char const *str)
{
    int index = 0;
    int len = 0;
    int nbr_mot = word_nbr(str);
    char **tab = malloc(sizeof(char *) * (nbr_mot + 1));
    if (nbr_mot == 0)
        return tab;
    int i = 0;
    while (i < nbr_mot + 1) {
        index = getindex((i), str);
        tab[i] = get_word(tab[i], str, index);
        i = i + 1;
    }
    tab[nbr_mot + 1] = NULL;
    return (tab);
}
