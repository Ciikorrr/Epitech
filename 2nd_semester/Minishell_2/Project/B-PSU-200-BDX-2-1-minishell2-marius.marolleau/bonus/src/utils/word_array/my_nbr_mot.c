/*
** EPITECH PROJECT, 2022
** my_nbr_word
** File description:
** nbr_word
*/

int my_alphanum(char c);

int my_nbr_mot(char *str)
{
    int nb = 0;
    int i = 0;
    while (str[i] == ' ') {
        i += 1;
    }
    for (; str[i] != '\0'; i += 1) {
        if (my_alphanum(str[i]) == 1 && (str[i + 1] == ' ' ||
        str[i + 1] == '\0')) {
            nb += 1;
        }
    }
    return nb;
}
