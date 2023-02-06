/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-myls-marius.marolleau
** File description:
** my
*/
#include <sys/stat.h>
#include <dirent.h>

#ifndef PROTOS_H_
    #define PROTOS_H_

void my_putchar(char c);
void my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
char *my_strcat(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int flag_a(struct dirent *entry, char *path, int argc, char **argv);
void do_flag(struct dirent *entry, DIR *dir, char **argv, int argc);
int is_flag_ls(char format);
int no_argument(struct dirent *entry, DIR *dir);
int have_flag(int argc, char **argv);
char find_flag(char **argv, int argc);
void search(char *argv, struct dirent *entry, int type, DIR *dir);
int find_type(char *argv, struct dirent *entry, int type);
int get_type(struct dirent *entry, char *argv, int type);
int flag_d(struct dirent *entry, char *path, int argc, char **argv);
void display_name(struct dirent *entry);
int error(DIR *dir, char *argv);
int flag_l(struct dirent *entry, char *path, int argc, char **argv);
void do_flag_no_arg(struct dirent *entry, DIR *dir, char **argv, int argc);
int find_type(char *argv, struct dirent *entry, int type);
int get_type(struct dirent *entry, char *argv, int type);
int flag_R(struct dirent *entry, char *path, int argc, char **argv);
int my_strlen(char const *str);
int my_printf(char const *format, ...);
void do_l(struct dirent *file);
int get_info(char *path, int total);
int compare(int argc, DIR *dir, struct dirent *file);
int info_l(int total, int argc, char *path, char *temp);
void error_handling(char *path);
void error_permission(char *path);
int my_strlen_tab(char **tab);
int flag_r(struct dirent *entry, char *path, int argc, char **argv);
int flag_t(struct dirent *entry, char *path, int argc, char **argv);
int my_strlen_tab(char **tab);
int compteur(char *path);

#endif /* !PROTOS_H_ */
