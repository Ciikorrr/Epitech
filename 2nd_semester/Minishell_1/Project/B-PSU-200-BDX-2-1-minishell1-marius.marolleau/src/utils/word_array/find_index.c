/*
** EPITECH PROJECT, 2022
** find_index
** File description:
** find the next index
*/

#include <stdio.h>
int my_alphanum(char c);

int find_index(char *str, int idx_pcd)
{
    for (; str[idx_pcd] != '\n'; idx_pcd += 1) {
        if (my_alphanum(str[idx_pcd]) == 0 &&
            my_alphanum(str[idx_pcd + 1]) == 1) {
            return idx_pcd + 1;
        }
    }
    return 0;
}
