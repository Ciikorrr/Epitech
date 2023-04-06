/*
** EPITECH PROJECT, 2022
** Start_projet
** File description:
** main
*/
#include "protos.h"
#include "macros.h"
int lemin_algo(void);

int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 1)
        return ERROR_EPITECH;
    return lemin_algo();
}
