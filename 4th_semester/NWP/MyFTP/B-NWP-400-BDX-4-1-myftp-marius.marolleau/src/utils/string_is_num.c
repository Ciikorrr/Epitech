/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** stringisnum
*/
#include "../../include/macros.h"
#include <ctype.h>

int string_is_num(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i]) == 0)
            return ERROR;
    }
    return SUCCESS;
}
