/*
** EPITECH PROJECT, 2022
** my_print_params;c
** File description:
** print_params
*/

int my_putstr(char *str);

void my_putchar(char c);

int my_print_params(int argc, char **argv)
{
    int i = 0;
    while (i != argc) {
        my_putstr(argv[i]);
        my_putchar('\n');
        i += 1;
    }
    return (0);
}
