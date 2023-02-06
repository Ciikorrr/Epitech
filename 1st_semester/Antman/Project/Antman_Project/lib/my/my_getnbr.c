/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** ouais
*/

int my_getnbr(char const *str)
{
    int min = -2147483648;
    int max = 2147483647;
    int res = 0;
    int s = 1;
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if ((res * s) == max || (res * s) == min)
            return (0);
        if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
            s = -1;
        if (str[i] >= '0' && str[i] <= '9')
            res = (res * 10 + (str[i] - '0'));
        if ((str[i] >= '0' && str[i] <= '9') && (str[i + 1] < '0') ||
            (str[i + 1] > '9'))
            return (res * s);
    }
    return (res * s);
}
