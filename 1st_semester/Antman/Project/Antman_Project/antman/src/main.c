/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "../include/protos_compress.h"
#include "../include/macros.h"

int main(int argc, char **argv)
{
    if (do_antman(argc, argv) == ERROR_EPITECH)
        return ERROR_EPITECH;
    return SUCCESS_EPITECH;
}
