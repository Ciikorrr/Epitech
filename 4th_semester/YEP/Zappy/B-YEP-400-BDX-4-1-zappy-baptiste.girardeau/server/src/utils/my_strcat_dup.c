/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-celian.lombardot
** File description:
** strcat_dup
*/

#include <stdlib.h>
#include <string.h>

char *my_strcat_dup(char *dest, char *src, char *third)
{
    int len_dest = dest ? strlen(dest) : 0;
    int len_src = src ? strlen(src) : 0;
    int len_third = third ? strlen(third) : 0;
    char *final = malloc(len_dest + len_src + len_third + 2);

    if (!final)
        return NULL;
    if (dest)
        strcpy(final, dest);
    if (src)
        strcat(final, src);
    if (third)
        strcat(final, third);
    return final;
}
