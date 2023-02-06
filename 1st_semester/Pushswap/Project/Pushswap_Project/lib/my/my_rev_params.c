/*
** EPITECH PROJECT, 2022
** my_rev_params;c
** File description:
** reverse params
*/
void my_putchar(char c);

int my_putstr(char *str);

int main(int argc, char **argv)
{
    for (int i = argc - 1; i >= 0; i -= 1) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return (0);
}
