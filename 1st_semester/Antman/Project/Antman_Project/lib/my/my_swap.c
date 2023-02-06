/*
** EPITECH PROJECT, 2022
** my_swap
** File description:
** ouais
*/

void my_putchar(char c);

void my_swap(int *a, int *b)
{
    int tampon = *a;
    *a = *b;
    *b = tampon;
}
