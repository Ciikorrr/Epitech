/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** ouais
*/

char *my_revstr(char *str)
{
    int len = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        len = len + 1;
    }
    for (int i = 0; i < len; i++) {
        char temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        len = len - 1;
    }
    return (str);
}
