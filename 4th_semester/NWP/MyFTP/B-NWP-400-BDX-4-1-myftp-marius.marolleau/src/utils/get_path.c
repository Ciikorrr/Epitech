/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** get_path
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "myftp.h"

char *get_path(char const *src)
{
    char *absolut_path = NULL;

    absolut_path = realpath(src, NULL);
    if (!absolut_path)
        return NULL;
    return absolut_path;
}
