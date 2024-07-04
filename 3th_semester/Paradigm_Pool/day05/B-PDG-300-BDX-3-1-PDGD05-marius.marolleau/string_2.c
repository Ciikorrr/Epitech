/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD05-marius.marolleau
** File description:
** string_2
*/
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void assign_s(string_t *this, const string_t *str)
{
    if (!this || !str)
        return;
    return assign_c(this, str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (!this || !s)
        return;
    string_destroy(this);
    string_init(this, s);
    return;
}

void append_s(string_t *this, const string_t *ap)
{
    if (!this || !ap)
        return;
    return append_c(this, ap->str);
}

void append_c(string_t *this, const char *ap)
{
    int len1 = 0;
    int len2 = 0;

    if (!this || !ap)
        return;
    len1 = strlen(this->str);
    len2 = strlen(ap);
    this->str = realloc(this->str, (len1 + len2 + 1) * sizeof(char));
    if (!this->str)
        return;
    this->str[len1 + len2] = '\0';
    this->str = strcat(this->str, ap);
}

char do_at(const string_t *this, size_t pos)
{
    if (!this)
        return -1;
    if (pos > strlen(this->str))
        return -1;
    return this->str[pos];
}
