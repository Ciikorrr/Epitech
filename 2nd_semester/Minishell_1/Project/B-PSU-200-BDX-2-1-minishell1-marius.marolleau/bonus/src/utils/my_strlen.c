/*
** EPITECH PROJECT, 2022
** my_lenstr
** File description:
** ouais
*/

void my_putchar(char c);

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0')
        i = i + 1;
    return (i);
}

int my_strlen_bis(char const *str)
{
    int i = 0;
    while (str[i] != '\n')
        i = i + 1;
    return (i);
}
