/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "protos.h"
#include "macros.h"

static int skip_header(unsigned char *str)
{
    int i = 0;
    int nb = 0;
    while (nb != 4) {
        if (str[i] == '\n')
            nb += 1;
        write(1, &str[i], 1);
        i += 1;
    }
    return i;
}

static void convert_char(unsigned char c)
{
    char nb[3] = {c / 100 % 10 + 48, c / 10 % 10 + 48, c % 10 + 48};
    int i = 0;
    while (nb[i] == '0' && i < 2) {
        i += 1;
    }
    for (; i < 3; i += 1) {
        write(1, &nb[i], 1);
    }
    write(1, "\n", 1);
}

int decompress_image(char unsigned *str)
{
    decompress_texte(str);
    free(str);
    return SUCCESS_EPITECH;
}
