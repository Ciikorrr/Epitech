/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** my_strstr
*/
#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int t2 = 0;
    for (int b = 0; to_find[b] != '\0'; b += 1) {
        t2 += 1;
    }
    int e = 0;
    int a = 0;
    for (e;str[e] != '\0'; e += 1) {
        if (str[e] == to_find[a]) {
            a += 1;
        } else {
            a = 0;
        }
        if (a == t2) {
            e = e - t2;
            return &str[e];
        }
    }
    return (NULL);
}
