/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static int count_word(char const *str)
{
    int count = 0;
    bool in_quote = false;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '"' && !in_quote) {
            in_quote = true;
            count += 1;
            i++;
            continue;
        }
        if (str[i] == '"' && in_quote) {
            in_quote = false;
            i++;
            continue;
        }
        i++;
    }
    return count;
}

static int my_is_not_separator(char c, char const *separator, bool *in_quote)
{
    for (int i = 0; separator[i] != '\0'; i += 1) {
        if (c == '"') {
            *in_quote = true;
            return false;
        }
        if (separator[i] == c || c == '\0')
            return false;
    }
    return (true);
}

char *fill_tab(int len, int index, char const *str)
{
    char *tab = malloc(sizeof(char) * (len + 1));

    tab[len] = '\0';
    for (int j = 0; j < len; j = j + 1) {
        tab[j] = str[index];
        index = index + 1;
    }
    return tab;
}

static char *get_word(const char *str, int i, char const *sep, bool *in_quote)
{
    int len = 0;
    int index = i;

    if (*in_quote) {
        while (str[i] != '"') {
            i++;
            len++;
        }
    } else {
        while (my_is_not_separator(str[i], sep, in_quote)) {
            len = len + 1;
            i = i + 1;
        }
    }
    return fill_tab(len, index, str);
}

static int getindex(int idx, const char *str, char const *sep, bool *in_quote)
{
    int nbr = 0;
    int i = 0;

    while (my_is_not_separator(str[i], sep, in_quote) == false)
        i = i + 1;
    while (str[i] != '\0') {
        if (nbr == idx) {
            return (i);
        }
        if (my_is_not_separator(str[i], sep, in_quote) == 0
        && my_is_not_separator(str[i + 1], sep, in_quote) == 1) {
            nbr = nbr + 1;
        }
        i = i + 1;
    }
    return (i);
}

char **my_str_to_word_array_separator_q(char const *str, char const *separator)
{
    int index = 0;
    int nbr_mot = count_word(str) + 1;
    char **tab = malloc(sizeof(char *) * (nbr_mot + 1));
    int i = 0;
    bool in_quote = false;

    if (!str || !separator || !tab)
        return NULL;
    tab[nbr_mot] = NULL;
    while (i < nbr_mot) {
        index = getindex((i), str, separator, &in_quote);
        tab[i] = get_word(str, index, separator, &in_quote);
        i = i + 1;
    }
    return (tab);
}
