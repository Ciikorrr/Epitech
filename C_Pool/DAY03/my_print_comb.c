/*
** EPITECH PROJECT, 2022
** my_print_comb
** File description:
** comb
*/

void my_putchar(char c);

int my_print_num(int i, int j, int k)
{
    if (i < j && j < k) {
        my_putchar(i + 48);
        my_putchar(j + 48);
        my_putchar(k + 48);
        my_putchar(',');
        my_putchar(' ');
    }
}

int my_print_comb(void)
{
    int i = 0;
    int j = 1;
    int k = 2;

    while (i != 7 || j != 8 || k != 9) {
        if (k >= 10) {
            k = 0;
            j += 1;
        }
        if (j >= 9){
            j = 0;
            i += 1;
        }
        my_print_num(i, j, k);
        k += 1;
    }
    my_putchar(i + 48);
    my_putchar(j + 48);
    my_putchar(k + 48);
    my_putchar('\n');
}
