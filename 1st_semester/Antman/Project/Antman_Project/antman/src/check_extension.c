/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "protos_compress.h"
#include "macros.h"

int check_image(char *str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        len += 1;
    }
    if (str[len - 1] == 'm' && str[len - 2] == 'p' && str[len - 3] == 'p' &&
    str[len - 4] == '.')
        return SUCCESS_EPITECH;
    return ERROR_EPITECH;
}

int check_html(char *str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        len += 1;
    }
    if (str[len - 1] == 'l' && str[len - 2] == 'm' && str[len - 3] == 't' &&
    str[len - 4] == 'h' && str[len - 5] == '.')
        return SUCCESS_EPITECH;
    return ERROR_EPITECH;
}

int check_texte(char *str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        len += 1;
    }
    if (str[len - 1] == 'r' && str[len - 2] == 'y' && str[len - 3] == 'l' &&
    str[len - 4] == '.')
        return SUCCESS_EPITECH;
    return ERROR_EPITECH;
}
