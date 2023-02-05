/*
** EPITECH PROJECT, 2022
** my_print_revalpha
** File description:
** reverse
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    int i = 0;

    for (i = 122;i > 96;i -= 1) {
        my_putchar(i);
    }
    my_putchar('\n');
    return (0);
}
