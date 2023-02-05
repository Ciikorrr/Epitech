/*
** EPITECH PROJECT, 2022
** my_print_digits
** File description:
** write digits
*/

void my_putchar(char c);

int my_print_digits(void)
{
    int  i = 0;

    for (i = 48; i < 58; i += 1) {
    my_putchar(i);
    }
    my_putchar('\n');
    return (0);
}
