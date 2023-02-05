/*
** EPITECH PROJECT, 2022
** my_show_word_array
** File description:
** show word array
*/
char *putstr(char *c);

char my_putchar(char c);

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != 0; i += 1) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}
