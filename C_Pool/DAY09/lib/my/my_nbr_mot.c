/*
** EPITECH PROJECT, 2022
** my_nbr_word
** File description:
** nbr_word
*/

int my_alpha(char c);

int my_nbr_mot(char *str)
{
    int nb = 1;
    int i = 0;
    while (my_alpha(str[i]) != 1) {
        i += 1;
    }
    
    for (i; str[i] != '\0'; i += 1) {
	if (my_alpha(str[i]) == 0 && my_alpha(str[i + 1]) == 1) {
            nb += 1;
        }
    }
    return nb;
}
