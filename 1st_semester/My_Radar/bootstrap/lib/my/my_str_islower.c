/*
** EPITECH PROJECT, 2022
** my_programm
** File description:
** programm
*/
#include <stddef.h>

int my_str_islower(char const *str)
{
    if (str == NULL) {
        return 1;
    }
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (!(str[i] >= 'a' && str[i] <= 'z')) {
            return 0;
        }
    }
    return 1;
}
