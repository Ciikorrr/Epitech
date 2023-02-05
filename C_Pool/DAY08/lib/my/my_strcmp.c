/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** reproduce a word
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);
    int i = 0;
    while (i < len_s1) {
        if (len_s1 != len_s2) {
            return -1;
        }
    }
    for (int j = 0; s1[i] != '\0'; i += 1) {
        if (s1[i] != s2[i]) {
            return -1;
        }
    }
    return 0;
}
