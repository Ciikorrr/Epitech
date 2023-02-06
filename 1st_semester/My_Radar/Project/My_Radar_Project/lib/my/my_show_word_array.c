/*
** EPITECH PROJECT, 2022
** my_show_word_array
** File description:
** show word array
*/
#include <stddef.h>
#include <unistd.h>
#include "../../include/protos.h"
void my_putchar(char c);
void my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    int size = nb_char(tab[1], 0);
    for (int i = 0; tab[i] != NULL; i += 1) {
        write(1, tab[i], size + 1);
        my_putstr("\n");
    }
    return (0);
}

int my_show_word_array_bsq(char * const *tab)
{
    int size = nb_char(tab[1], 0);
    for (int i = 1; tab[i] != NULL; i += 1) {
        write(1, tab[i], size + 1);
    }
    return (0);
}
