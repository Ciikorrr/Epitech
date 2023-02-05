/*
** EPITECH PROJECT, 2022
** my_strupcase.c
** File description:
** upper case
*/

char *my_strupcase(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == 32 || str[i] < 'a' && str[i] > 'z') {
            i += 1;
        } else {
            str[i] = str[i] - 32;
            i += 1;
        }
    }
    return (str);
}
