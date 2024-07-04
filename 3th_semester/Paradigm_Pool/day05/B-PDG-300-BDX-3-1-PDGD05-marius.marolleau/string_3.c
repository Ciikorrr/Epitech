/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD05-marius.marolleau
** File description:
** string3
*/
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>
#include <string.h>

void clear(string_t *this)
{
    if (!this)
        return;
    free(this->str);
    this->str = strdup("");
    return;
}

int length(const string_t *this)
{
    if (!this)
        return -1;
    return strlen(this->str);
}

int compare_s(const string_t *this, const string_t *str)
{
    return compare_c(this, str->str);
}

int compare_c(const string_t *this, const char *str)
{
    return strcmp(this->str, str);
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t length;

    if (this == NULL || this->str == NULL || s == NULL)
        return 0;
    length = strlen(this->str) + 1;
    if (pos > length)
        return 0;
    n = MIN(length - pos, n);
    strncpy(s, this->str + pos, n);
    return n;
}
