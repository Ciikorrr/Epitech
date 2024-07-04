/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD05-marius.marolleau
** File description:
** string_5
*/
#include "string.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char **split_c(const string_t *this, char separator)
{
    if (!this)
        return NULL;
    return my_str_to_word_array_separator(this->str, &separator);
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    return insert_c(this, pos, str->str);
}

int check_position(size_t pos, string_t *this, const char *str)
{
    char *ptr = NULL;

    if (pos == 0) {
        ptr = strdup(this->str);
        free(this->str);
        string_init(this, str);
        this->append_c(this, ptr);
        free(ptr);
        return 1;
    }
    if (pos > strlen(this->str)) {
        this->append_c(this, str);
        return 1;
    }
    return 0;
}

void fill_str(string_t *this, const char *str, size_t pos, int temp)
{
    int i = 0;
    char *new = NULL;
    int idx = 0;

    if (!this || !str)
        return;
    new = calloc((strlen(str) + strlen(this->str) + 1), sizeof(char));
    new[strlen(str) + strlen(this->str)] = '\0';
    while (idx < strlen(str) + strlen(this->str)) {
        if (i > pos - 1 && temp != 0) {
            new[idx] = str[strlen(str) - temp];
            temp--;
        } else {
            new[idx] = this->str[i];
            i++;
        }
        idx++;
    }
    free(this->str);
    this->str = new;
}

void insert_c(string_t *this, size_t pos, const char *str)
{
    int temp = 0;

    if (!this || !str)
        return;
    if (check_position(pos, this, str) == 1)
        return;
    temp = strlen(str);
    return fill_str(this, str, pos, temp);
}
