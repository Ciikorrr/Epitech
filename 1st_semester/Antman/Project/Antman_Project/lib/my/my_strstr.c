/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** ouais
*/

#include <stddef.h>
int my_strlen(char const *str);

char *my_strstr(char *str, char const *to_find)
{
    int len = my_strlen(to_find);
    int i = 0;
    int temp = 0;
    while (str[i] != '\0') {
        if (str[i] == to_find[temp] && str[i + 1] != to_find[temp])
            temp = temp + 1;
        else
            temp = 0;
        if (temp == len)
            return (&str[i - (len - 1)]);
        i = i + 1;
    }
    return NULL;
}
