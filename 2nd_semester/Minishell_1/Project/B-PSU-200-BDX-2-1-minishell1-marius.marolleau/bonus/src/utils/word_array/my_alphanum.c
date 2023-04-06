/*
** EPITECH PROJECT, 2022
** my_alpha
** File description:
** my_alpha
*/

int my_alphanum(char c)
{
    if (c != ' ' && c != '\t') {
        return 1;
    }
    return 0;
}
