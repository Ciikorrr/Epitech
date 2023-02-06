/*
** EPITECH PROJECT, 2022
** my_sort_params.c
** File description:
** sort params
*/
#include <stddef.h>

void my_putchar(char c);

int my_putstr(char *str);

int main(int argc, char **argv)
{
    int j = 0;
    for (int i = 0; i < argc - 1; i += 1) {
        while (argv[i][j] == argv[i + 1][j]) {
            j += 1;
        }
        if (argv[i][j] > argv[i + 1][j]) {
            char *mem = argv[i + 1];
            argv[i + 1] = argv[i];
            argv[i] = mem;
            i = 0;
        }
        j = 0;
    }
    for (int i = 0;i < argc; i += 1) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return (0);
}
