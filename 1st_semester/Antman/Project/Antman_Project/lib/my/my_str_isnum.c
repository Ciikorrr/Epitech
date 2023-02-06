/*
** EPITECH PROJECT, 2022
** my_str_isalpha.c
** File description:
** ouais
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] < '0' || str[i] > '9') {
            return (0);
        }
    }
    return (1);
}
