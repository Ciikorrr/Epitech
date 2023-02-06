/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_alpha
*/

int my_alpha(char c)
{
    if (!(c >= 'a' && c <= 'z' || c >= 'A' &&
        c <= 'Z')) {
        return 0;
    }
    return 1;
}
