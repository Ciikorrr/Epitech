/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** str lenght
*/

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}
