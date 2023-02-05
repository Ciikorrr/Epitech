/*
** EPITECH PROJECT, 2022
** my_add.c
** File description:
** add
*/
#include <stdlib.h>
#include <stdio.h>

int my_strlen_index(char *str, int index);

int find_index(char *str, int idx_pcd);

int my_nbr_mot(char *str);

/*
1 == TRUE
0 == FALSE
*/

int verif(char *str)
{
    int index = 0;
    if (my_alpha(str[0]) == 1)
        index = 0;
    else
        index = find_index(str,0);
    return index;
}

char **my_str_to_word_array(char *str)
{
    int nb_word = my_nbr_mot(str);
    int index = verif(str);
    char **tab = malloc(sizeof(char *) * (nb_word + 1));
    int index_str = 0;
    for (int i = 0; i < nb_word; i += 1) {
        int taille = my_strlen_index(str, index);
        index_str = index;
        tab[i] = malloc(sizeof(char) * (taille + 1));
        for (int j = 0; j < taille; j += 1) {
            tab[i][j] = str[index_str];
            index_str += 1;
        }
        tab[i][taille] = '\0';
        index = find_index(str, index + 1);
    }
    tab[nb_word] = NULL;
    return tab;
}
