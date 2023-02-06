/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
int my_special_getnbr(char *str, int *index);

void init_start(char *slice, int *start, int *idx)
{
    *start = my_special_getnbr(slice, idx);
}

void init_end(char *slice, int *end, int *idx)
{
    *end = my_special_getnbr(slice, idx);
}

void init_step(char *slice, int *step, int *idx)
{
    *step = my_special_getnbr(slice, idx);
}
