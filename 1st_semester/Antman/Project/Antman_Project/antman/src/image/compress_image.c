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
#include "protos_compress.h"

static int len_file(char *str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        len += 1;
    }
    return len;
}

static int skip_header(char *str)
{
    int i = 0;
    while (str[i] != '2' || str[i + 1] != '5' || str[i + 2] != '5' ||
    str[i + 3] != '\n') {
        write(1, &str[i], 1);
        i += 1;
    }
    return i;
}

static int convert_char(char *str, int start, int len)
{
    u_int8_t c = 0;
    int nb = 0;
    while (start != len) {
        nb = 0;
        while (str[start] != '\n') {
            nb = nb * 10 + str[start] - '0';
            start += 1;
        }
        c = nb;
        write(1, &c, 1);
        start += 1;
    }
    return 0;
}

int compress_image(char *str)
{
    huffman_compression_main(str);
    return SUCCESS_EPITECH;
}
