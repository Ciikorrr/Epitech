/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** put str
*/
#include <unistd.h>
void my_putchar(char c);

int my_putstr(char const *str)
{
    if (str == NULL)
        return -1;
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
    return 0;
}
