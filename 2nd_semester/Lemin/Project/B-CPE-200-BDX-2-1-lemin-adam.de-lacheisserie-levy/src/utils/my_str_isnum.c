/*
** EPITECH PROJECT, 2022
** my_str_isnum
** File description:
** str is num
*/

int my_str_isnum(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return 1;
        i += 1;
    }
    return 0;
}
