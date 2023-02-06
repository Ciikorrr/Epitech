/*
** EPITECH PROJECT, 2022
** my_programm
** File description:
** programm
*/
#include <stddef.h>

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (!( str[i] >= 32 && str[i] <= 126)) {
            return 0;
        }
    }
    return 1;
}
