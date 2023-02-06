/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#ifndef PROTOS_MAP_H
    #define PROTOS_MAP_H

int check_file(char *str);
char **create_map(char **tab, char const *filepath);
char **create_empty_map(void);
int check_syntaxe(char *line);
int check_num(char *line, int i);
int check_alpha(char *line, int i);
int check_special_caracters(char *line, int i);
int check_position(char *line);
int check_nb_boat(char *line, int size);
int check_direction(char *line);
int error_script(char *line, int size);
int check_correct_position_pos(char *line);
int check_correct_position_neg(char *line);
char **add_boat_on_map(char *line, char **tab);
int show_map(char **map);
int check_pid(char const *str);
int check_args(int argc, char **argv);
int do_error_handling(int argc, char **argv);
int check_file_bis(char *str);

#endif /* PROTOS_MAP_H */
