/*
** EPITECH PROJECT, 2022
** my_print_alpha
** File description:
** ouais
*/

void my_putchar(char c);

int my_print_alpha(void)
{
    for (char i = 97; i < 123; i += 1) {
        my_putchar(i);
        my_putchar('\0');
    }
    my_putchar('\n');
    return (0);
}
