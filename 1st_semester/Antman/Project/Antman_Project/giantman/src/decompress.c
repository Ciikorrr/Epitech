/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "../include/macros.h"
#include "../include/protos.h"

int choice_decompress(int argc, char **argv)
{
    if (error_handling(argc, argv) == ERROR_EPITECH)
        return ERROR_EPITECH;
    char *str = file_to_str(argv[1]);
    if (argv[2][0] != '1' && argv[2][0] != '2' && argv[2][0] != '3')
        return ERROR_EPITECH;
    return decompress_texte(str);
}

int decompress_file(int argc, char **argv)
{
    if (argc == 3) {
        if (choice_decompress(argc, argv) == SUCCESS_EPITECH)
            return SUCCESS_EPITECH;
    }
    return ERROR_EPITECH;
}
