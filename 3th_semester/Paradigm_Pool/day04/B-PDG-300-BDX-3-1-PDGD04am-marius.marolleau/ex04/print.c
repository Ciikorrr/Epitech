/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD04am-marius.marolleau
** File description:
** print
*/
#include <strings.h>
#include <stdio.h>
#include "print.h"
#include <string.h>
#include <stdlib.h>

void print_normal(const char *str)
{
    if (!str)
        return;
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    char *str2 = NULL;
    int len = -1;
    char temp = '\0';

    if (!str)
        return;
    str2 = strdup(str);
    for (int i = 0; str2[i] != '\0'; i++) {
        len = len + 1;
    }
    for (int i = 0; i < len; i++) {
        temp = str2[i];
        str2[i] = str2[len];
        str2[len] = temp;
        len = len - 1;
    }
    printf("%s\n", str2);
    free(str2);
}

void print_upper(const char *str)
{
    char *str2 = NULL;
    int i = 0;

    if (!str)
        return;
    str2 = strdup(str);
    while (str2[i] != '\0') {
        if (str2[i] >= 'a' && str2[i] <= 'z') {
            str2[i] -= 32;
        }
        i += 1;
    }
    printf("%s\n", str2);
    free(str2);
}

void print_42(const char *str)
{
    (void)str;
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    if (!str)
        return;
    print[action].function(str);
}
