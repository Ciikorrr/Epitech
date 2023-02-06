/*
** EPITECH PROJECT, 2022
** my_show_word_array
** File description:
** ouais
*/

#include <stddef.h>

int my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != NULL; i = i + 1) {
        my_putstr(tab[i]);
    }
    return (0);
}
