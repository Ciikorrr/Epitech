/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#ifndef UTILS_H_
    #define UTILS_H_
    int get_nb_line(char const *filepath);
    char **file_to_tab(char const *filepath);
    int print_tab(char **map);
    int get_line(char const *file);
    int get_nb_line(char const *filepath);
    int length_map(char **map);
    int do_width(char *map);
    char *my_strdup(char *src);
    int my_strlen(char const *str);
    void my_putchar(char c);
    int my_putstr(char const *str);
    void redirect_all_std(void);
    int error_handling(int argc, char **argv, char ***map);
    int compare(char **map, int i);
    int check_map(char **map);
    int do_solver(char **map);

#endif /* UTLIS_H_ */
