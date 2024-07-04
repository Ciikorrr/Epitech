/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** command_parser
*/

/*    140  "marius" "10 25 40 */
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

static bool is_separator(char const *is_separator, char const c)
{
    for (int i = 0; is_separator[i] != '\0'; i++) {
        if (is_separator[i] == c)
            return true;
    }
    return false;
}

static int count_word(char *str, char const *separator)
{
    int nb_word = 0;
    bool in_quote = false;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '"')
            in_quote = !in_quote;
        if (!in_quote && is_separator(separator, str[i]) &&
        !is_separator(separator, str[i + 1]))
            nb_word++;
        i++;
    }
    return nb_word;
}

static
void skip_separator(char *str, char const *separator, bool *in_quote, int *idx)
{
    int index = *idx;

    while (str[index] != '\0' && is_separator(separator, str[index]) == true)
        index++;
    if (str[index] == '"') {
        *in_quote = true;
        index++;
    }
    *idx = index;
    return;
}

static
int len_word(char *str, char const *separator, int index, bool *in_quote)
{
    int len = 0;

    if (*in_quote) {
        while (str[index] != '\0' && str[index] != '"') {
            index++;
            len++;
        }
        return len;
    }
    while (str[index] != '\0' && !is_separator(separator, str[index])) {
        index++;
        len++;
    }
    return len;
}

static
char *get_word(int *index, char *str, char const *separator, bool *in_quote)
{
    int len = len_word(str, separator, *index, in_quote);
    char *return_str = malloc(sizeof(char) * (len + 1));
    int i = 0;

    return_str[len] = '\0';
    while (i < len) {
        return_str[i] = str[*index + i];
        i++;
    }
    if (*in_quote) {
        *in_quote = !*in_quote;
        i++;
    }
    *index += i;
    return return_str;
}

char **command_parser(char *str, char const *separator)
{
    int nb_word = count_word(str, separator);
    char **tab = malloc(sizeof(char *) * (nb_word + 1));
    int i = 0;
    bool in_quote = false;
    int index = 0;

    skip_separator(str, separator, &in_quote, &index);
    if (!tab)
        return NULL;
    tab[nb_word] = NULL;
    while (i < nb_word) {
        tab[i] = get_word(&index, str, separator, &in_quote);
        skip_separator(str, separator, &in_quote, &index);
        i++;
    }
    return tab;
}
