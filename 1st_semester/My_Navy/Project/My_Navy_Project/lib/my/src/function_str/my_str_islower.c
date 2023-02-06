/*
** EPITECH PROJECT, 2022
** my_str_isalpha.c
** File description:
** ouais
*/

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] < 'a' || str[i] > 'z') {
            return (0);
        }
    }
    return (1);
}
