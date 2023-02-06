/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-myls-marius.marolleau
** File description:
** struct_flag
*/
#include <sys/stat.h>
#include <dirent.h>
#include "protos.h"

#ifndef STRUCT_FLAG_H_
    #define STRUCT_FLAG_H_

    #include "protos.h"

typedef struct flags_tab {
    char flag;
    int (*function)(struct dirent *entry, char *path, int argc, char **argv);
}flags_tab;

flags_tab tab_flag2[] = {
{'a', &flag_a},
{'d', &flag_d},
{'l', &flag_l},
{'r', &flag_r},
{'t', &flag_t}
};
    #define TAB_SIZE 5
#endif /* !STRUCT_FLAG_H_ */
