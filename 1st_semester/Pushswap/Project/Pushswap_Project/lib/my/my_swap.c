/*
** EPITECH PROJECT, 2022
** my_swap
** File description:
** swap
*/

void  my_swap(int *a, int *b)
{
    int memory;
    memory = *a;
    *a = *b;
    *b = memory;
}
