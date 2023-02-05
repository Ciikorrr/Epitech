/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** my_strstr
*/
#include <stddef.h>

int my_strlen(char c);

char *my_strstr(char *str, char const *to_find)
{
    int t2 = my_strlen(to_find);
    if (!to_find && t2 = "") {
        return str
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
            return &str[e + 1];
        }
    }
    return (NULL);
}
