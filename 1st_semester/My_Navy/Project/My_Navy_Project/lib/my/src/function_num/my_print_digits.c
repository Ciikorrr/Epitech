/*
** EPITECH PROJECT, 2022
** my_print_digits
** File description:
** Print all the digits in ascending order
*/

void my_putchar(char c);

int my_print_digits(void)
{
    for (int i = 48; i < 58; i = i + 1) {
        my_putchar(i);
        my_putchar('\0');
    }
    my_putchar('\n');
    return (0);
}
