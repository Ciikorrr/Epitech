/*
** EPITECH PROJECT, 2022
** is_print
** File description:
** ouais
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] < 32) {
            return (0);
        }
    }
    return (1);
}
