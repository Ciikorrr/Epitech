/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD04pm-marius.marolleau
** File description:
** mul_div
*/
#include <stdio.h>

void mul_div_long(int a, int b, int *mul, int *div)
{
    *mul = (a * b);
    if (b == 0)
        *div = 42;
    else
        *div = (a / b);
}

void mul_div_short(int *a, int *b)
{
    int tmp = *a;

    *a = (*a * *b);
    if (*b == 0)
        *b = 42;
    else
        *b = (tmp / *b);
}
