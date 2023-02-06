/*
** EPITECH PROJECT, 2022
** my_evil_str
** File description:
** ouais
*/

char *my_evil_str(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    int x = 0;
    for (int j = (i - 1); j >= x; j = j - 1) {
        char temp = str[x];
        str[x] = str[j];
        str[j] = temp;
        x = x + 1;
    }
    return (str);
}
