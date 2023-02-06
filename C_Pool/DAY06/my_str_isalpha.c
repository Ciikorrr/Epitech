/*
** EPITECH PROJECT, 2022
** my_str_isalpha
** File description:
** isalpha
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if ( !(str[i] >= 'a' && str[i] <= 'z') || (
            str[i] >= 'A' && str[i] <= 'Z')) {
            return 0;
        }
    }
    return 1;
}
