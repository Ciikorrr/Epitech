/*
** EPITECH PROJECT, 2022
** my_strupcase
** File description:
** ouais
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] == ' ')
            i++;
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
    return (str);
}
