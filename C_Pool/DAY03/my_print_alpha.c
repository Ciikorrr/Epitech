/*
** EPITECH PROJECT, 2022
** my_print_alpha
** File description:
** my_alpha
*/

void my_putchar(char c);

int my_print_alpha(void)
{
    int i;

    for (i = 97; i < 123; i += 1) {
        my_putchar(i);
    }
    my_putchar('\n');
    return (0);
}
