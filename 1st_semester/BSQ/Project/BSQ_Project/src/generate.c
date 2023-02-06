/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-BSQ-marius.marolleau
** File description:
** generate
*/
#include <stdlib.h>
#include <stddef.h>
#include "protos.h"
#include <sys/stat.h>
#include "macros.h"

char **malloc_generate_map(int size)
{
    int count = 0;
    char **map = malloc(sizeof(char *) * (size + 1));
    map[size] = NULL;
    for (count = 0; count < size; count += 1) {
        map[count] = malloc(sizeof(char) * (size + 2));
        map[count][size + 1] = '\0';
    }
    return map;
}

char **complete_map(char **map, int size, char *patern)
{
    int index = 0;
    int count = 0;
    for (int i = 0; i < size; i += 1) {
        for (int j = 0; j < size; j += 1) {
            map[i][j] = patern[count];
            count += 1;
            index = j;
            (patern[count] == '\0' ? count = 0 : 0);
        }
        map[i][index + 1] = '\n';
    }
    return map;
}

char **generation_map(char *size, char *patern)
{
    int nb_size = my_getnbr(size);
    if (nb_size == 0) {
        exit(ERROR_EPITECH);
    }
    char **map = malloc_generate_map(nb_size);
    map = complete_map(map, nb_size, patern);
    return map;
}

void bsq_basic(char **map, char **argv)
{
    struct stat file;
    error_file(file, argv[1]);
    char *str = file_to_str(argv[1]);
    error_handling(str, file);
    map = str_to_tab(str);
    error_map(map);
    map = my_bsq(map);
    my_show_word_array_bsq(map);
    for (int i = 0; map[i] != NULL; i += 1) {
        free(map[i]);
    }
    free(map);
    free(str);
}

void bsq_gen(char **map, char **argv)
{
    map = generation_map(argv[1], argv[2]);
    map = my_bsq2(map);
    my_show_word_array(map);
    for (int i = 0; map[i] != NULL; i += 1) {
        free(map[i]);
    }
    free(map);
}
