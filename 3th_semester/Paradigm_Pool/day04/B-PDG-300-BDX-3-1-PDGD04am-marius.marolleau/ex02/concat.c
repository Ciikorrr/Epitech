/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD04pm-marius.marolleau
** File description:
** concat
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concat.h"

static char *get_new(int len_dest, int len_src, const char *dest, char *src)
{
    char *res = malloc(sizeof(char) * (len_dest + len_src + 2));
    int i = 0;

    if (res == NULL)
        return NULL;
    for (int j = 0; j < len_dest + len_src + 2; j += 1)
        res[j] = '\0';
    for (int j = 0; j < len_dest; j += 1){
        res[i] = dest[j];
        i += 1;
    }
    for (int j = 0; j < len_src; j += 1){
        res[i] = src[j];
        i += 1;
    }
    return res;
}

char *my_strcat_dup(const char *dest, const char *src)
{
    int len_dest = 0;
    int len_src = 0;

    if (dest == NULL)
        return src;
    if (src == NULL)
        return dest;
    len_dest = strlen(dest);
    len_src = strlen(src);
    return get_new(len_dest, len_src, dest, src);
}

void concat_strings(const char *str1, const char *str2, char **res)
{
    *res = my_strcat_dup(str1, str2);
}

void concat_struct(concat_t *str)
{
    str->res = my_strcat_dup(str->str1, str->str2);
}
