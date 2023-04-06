/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-lemin-adam.de-lacheisserie-levy
** File description:
** lemin
*/

#include "macros.h"
#include "struct_lemin.h"
#include "protos.h"
int parser(lemin_t *data);

int lemin_algo(void)
{
    lemin_t data = {0};
    if (parser(&data) == ERROR_EPITECH)
        return ERROR_EPITECH;
    if (check_error(&data) == ERROR_EPITECH)
        return ERROR_EPITECH;
    return SUCCESS_EPITECH;
}
