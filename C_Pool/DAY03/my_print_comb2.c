/*
** EPITECH PROJECT, 2022
** my_print_comb2
** File description:
** comb2
*/

void my_putchar(char c);

int my_print_nume(int i, int j)
{
    if (i < j) {
    my_putchar((i / 10) + 48);
    my_putchar((i % 10) + 48);
    my_putchar(' ');
    my_putchar((j / 10) + 48);
    my_putchar((j % 10) + 48);
    my_putchar(',');
    my_putchar(' ');
    }
}

int my_print_comb2(void)
{
    int i = 0;
    int j = 1;

    while (i != 98 || j != 99) {
        if (j >= 100) {
            j = 0;
     	    i += 1;
        }
        my_print_nume(i, j);
        j += 1;
    }

    my_putchar((i / 10) + 48);
    my_putchar((i % 10) + 48);
    my_putchar(' ');
    my_putchar((j / 10) + 48);
    my_putchar((j % 10) + 48);
    my_putchar('\n');
}
