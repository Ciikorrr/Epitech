/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** code_bad_args
*/

#include <stdio.h>
#include "../../include/macros.h"

int code_bad_args(char **cmd)
{
    (void)cmd;
    printf("Bad argument provided !\n");
    return SUCCESS;
}
