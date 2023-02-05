/*
** EPITECH PROJECT, 2022
** my_alpha
** File description:
** my_alpha
*/

int my_alphanum(char c)
{
    if ((c >= 'a' && c <= 'z' || c >= 'A' &&
        c <= 'Z' || c >= '0' && c <= '9')) {
        return 1;
    }
    return 0;
}
