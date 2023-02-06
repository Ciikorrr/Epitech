/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdlib.h>
int my_strlen(char *str);

char *strcat_bis(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    int a = 0;
    char *dest = malloc(sizeof(char) * (len1 + len2 + 1));
    dest[len1 + len2] = '\0';
    for (int i = 0; dest[i] != '\0'; i += 1) {
        dest[i] = 'a';
    }
    for (int start = 0; start < len1; start += 1) {
        dest[start] = str1[start];
    }
    for (int second = (len1); second < (len2 + len1); second += 1) {
        dest[second] = str2[a];
        a += 1;
    }
    return dest;
}
