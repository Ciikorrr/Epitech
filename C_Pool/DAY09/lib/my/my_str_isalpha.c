/*
** EPITECH PROJECT, 2022
** my_str_isalpha
** File description:
** isalpha
*/

char *my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i += 1)
        if (str[i] > 'a' && str[i] < 'z' || str[i] > 'A' && str[i] < 'Z') {
            return 1;
        }
    return 0;
}
