/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#ifndef UTILS_H_
    #define UTILS_H_

    char *strcat_dup(char *str1, char *str2);
    int my_strlen(char const *str);
    int free_tab(char **tab);
    int my_strcmp(char const *s1, char const *s2);
    void my_putchar(char c);
    void my_putstr(char const *str);
    int my_put_nbr(int nb);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strdup(char const *src);
    char *my_strcpy(char *dest, char const *src);
    int length_tab(char **tab);
    int nbr_word_separator(char *str, char *separator);
    int loop_separator(char c, char *separator);
    int find_index_separator(char *str, int idx_pcd, char *separator);
    int my_strlen_index_separator(char *str, int index, char *separator);
    char **my_str_to_word_array_separator(char *str, char *separator);
    int where_is_start(char *separator, char *str);
    int my_strlen_index(char *str, int index);
    int my_str_isalpha(char const *str);
    int my_strlen_bis(char const *str);
    int my_putstr_choose(char *str, int output);
    int my_nbr_mot(char *str);
    char *strcat_dup(char *str1, char *str2);

#endif /* UTILS_H_ */
