/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include "utils.h"

int my_putstr_choose(char *str, int output)
{
    int len = my_strlen(str);
    write(output, str, len);
    return 0;
}
