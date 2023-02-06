/*
** EPITECH PROJECT, 2022
** my_print_revalpha
** File description:
** Print the alphabet in reverse order
*/

void my_putchar(char c);

char my_print_revalpha(void)
{
    for (char i = 122; i > 96; i = i - 1) {
        my_putchar(i);
        my_putchar('\0');
    }
    my_putchar('\n');
}
