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
    int x = 0;
    for (idx_pcd; str[idx_pcd] != '\0'; idx_pcd += 1) {
        if (my_alphanum(str[idx_pcd]) == 0 &&
            my_alphanum(str[idx_pcd + 1]) == 1) {
            return idx_pcd + 1;
        }
    }
}
