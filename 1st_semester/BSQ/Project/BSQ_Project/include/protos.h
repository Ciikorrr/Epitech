/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-BSQ-marius.marolleau
** File description:
** protos
*/

#ifndef PROTOS_H_
    #define PROTOS_H_

    #include <sys/stat.h>
    #include "macros.h"
    #include "struct_bsq.h"
int my_getnbr(char const *str);
int is_square_of_size(char **map, int row, int col, int square_size);
char **my_bsq(char **map);
int my_show_word_array(char * const *tab);
char *file_to_str(char const *filepath);
char **str_to_tab(char const *str);
int my_strlen(char const *str);
char **malloc_generate_map(int size);
char **complete_map(char **map, int size, char *patern);
char **generation_map(char *size, char *patern);
int my_show_word_array_bsq(char * const *tab);
void bsq_gen(char **map, char **argv);
void bsq_basic(char **map, char **argv);
char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols);
int do_width(char *map, int width);
int lenght_map(char **map, int count);
char **single_line(char **map);
char my_putchar(char c);
int get_line(char const *file);
int biggest_line(char const *str);
int nb_char(char const *str, int index);
int next_index(char const *str, int i);
void error_handling(char *str, struct stat file);
void error_file(struct stat file, char *filepath);
void error_map(char **map);
void good_argv(char **argv);
char **my_bsq2(char **map);
char **extension_bsq(int width, int height, char **map, struct arg_bsq square);
char **display_square(struct arg_bsq *square, char **map);
void check_square(struct arg_bsq *square, char **map, int x, int y);
void compare(struct arg_bsq *square, int x, int y, int height);
char **extension_bsq2(int width, int height, char **map, struct arg_bsq square);
void special_case(int nb, char *argv);
int my_strcmp(char const *s1, char const *s2);
int my_putstr(char *str);

#endif /* !PROTOS_H_ */
