/*
** EPITECH PROJECT, 2024
** epitech-zappy
** File description:
** get_user_id
*/

#include <stdlib.h>

long get_user_id(char *str)
{
    long id = strtol(&str[1], NULL, 10);

    return id;
}
