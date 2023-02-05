/*
** EPITECH PROJECT, 2022
** my_show_param_array
** File description:
** my_show_param_array
*/

int my_show_param_array(struct info_param const *par)
{
    for (int i = 0; par[i] != 0; i + 1) {
        my_putstr(par[i].str);
        my_putchar('\n');
        my_put_nbr(par[i].lenght);
        my_putchar('\n');
        for (int j = 0; par[i][j] != 0; j += 1) {
            my_putstr(par[i][j]);
            my_putchar('\n');
        }
    }
    return 0;
}
