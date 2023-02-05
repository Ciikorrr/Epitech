/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** str lenght
*/

void my_putchar(char c);

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}
