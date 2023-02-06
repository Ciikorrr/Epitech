/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** reverse str
*/

char *my_revstr(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    int x = 0;
    for (int e = (i - 1); e >= x; e -= 1) {
        char mem = str[x];
        str[x] = str[e];
        str[e] = mem;
        x += 1;
    }
    return (str);
}
