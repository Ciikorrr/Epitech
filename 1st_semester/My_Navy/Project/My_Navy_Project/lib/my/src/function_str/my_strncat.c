/*
** EPITECH PROJECT, 2022
** my_strncat
** File description:
** ouais
*/

int my_strlen(char *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int len = my_strlen(dest);
    int i = 0;
    for (i = 0; src[i] != '\0' && i < nb; i = i + 1) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';
    return (dest);
}
