/*
** EPITECH PROJECT, 2023
** isnum
** File description:
** ui
*/

int is_num(char c)
{
    if (c >= '0' && c <= '9' || c == '-')
        return 0;
    else
        return 84;
}
