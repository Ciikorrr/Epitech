/*
** EPITECH PROJECT, 2022
** my_str_isalpha.c
** File description:
** ouais
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] < 'A' || str[i] > 'Z') {
            return (0);
        }
    }
    return (1);
}
