/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** string_is_num
*/

#include <ctype.h>
#include "../../../include/macros.h"

int string_is_num(char const *str)
{
    if (!str)
        return ERROR;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i]) == 0)
            return ERROR;
    }
    return SUCCESS;
}
