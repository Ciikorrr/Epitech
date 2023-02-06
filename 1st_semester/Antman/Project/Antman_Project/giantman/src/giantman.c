/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <fcntl.h>
#include <unistd.h>
#include "../include/macros.h"
#include "../include/protos.h"

int error_handling(int argc, char **argv)
{
    (void)argc;
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return ERROR_EPITECH;
    return SUCCESS_EPITECH;
}

void display_desc(void)
{
    char const *str = file_to_str("src/description.txt");
    int len = my_strlen(str);
    write(1, str, len);
}

int display_h(int argc, char **argv)
{
    if (argc == 2 && my_strcmp("-h", argv[1]) == 0) {
        display_desc();
        return SUCCESS_EPITECH;
    }
    return ERROR_EPITECH;
}

int do_giantman(int argc, char **argv)
{
    if (display_h(argc, argv) == SUCCESS_EPITECH) {
        return SUCCESS_EPITECH;
    }
    if (decompress_file(argc, argv) == SUCCESS_EPITECH) {
        return SUCCESS_EPITECH;
    }
    return ERROR_EPITECH;
}
