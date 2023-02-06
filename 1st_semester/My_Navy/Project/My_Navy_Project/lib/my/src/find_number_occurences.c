/*
** EPITECH PROJECT, 2022
** find n
** File description:
** ouais
*/

int find_n(char *str, char occurrence)
{
    int c = 0;
    for (int i = 0; str[i] != '\0'; i += 1)
        if (str[i] == occurrence)
            c += 1;
    return c;
}
