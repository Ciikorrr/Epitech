/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD05-marius.marolleau
** File description:
** string_4
*/
#include "string.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *c_str(const string_t *this)
{
    if (!this)
        return NULL;
    return this->str;
}

int empty(const string_t *this)
{
    if (!this || this->length(this) == 0)
        return 0;
    return 1;
}

int to_int(const string_t *this)
{
    return atoi(this->str);
}

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    return find_c(this, str->str, pos);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *temp = 0;

    if (!this || !str)
        return -1;
    temp = this->str + pos;
    temp = strstr(this->str + pos, str);
    if (!temp)
        return -1;
    return (temp - this->str);
}
