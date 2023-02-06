/*
** EPITECH PROJECT, 2022
** myh
** File description:
** ouais
*/

#ifndef LIBMAP_H_
    #define LIBMAP_H_

char **add_boat_pos(char *line, char **tab, int i);
char **add_boat_neg(char *line, char **tab, int i);
char **add_boat_on_map(char *line, char **tab);
int check_num(char *line, int i);
int check_alpha(char *line, int i);
int check_special_caracters(char *line, int i);
int check_syntaxe(char *line);
int check_nb_boat(char *line, int size);
int check_direction(char *line);
int check_correct_position_pos(char *line);
int check_correct_position_neg(char *line);
int check_position(char *line);
int error_script(char *line, int size);
char **create_empty_map(void);
char **loop(char **tab, int *size, char *line);
char **create_map(char **tab, char const *filepath);
int show_map(char **map);

#endif /* LIBMAP_H_ */
