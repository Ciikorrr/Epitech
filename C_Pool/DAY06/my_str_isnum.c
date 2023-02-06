/*
** EPITECH PROJECT, 2022
** my_programm
** File description:
** programm
*/

int my_str_isnum(char *str)
{
    int i = 0;
    for (; str[i] != '\0'; i += 1) {
        if (!(str[i] >= '0' && str[i] <= '9')) {
            return 0;
        }
    }
    return 1;
}
