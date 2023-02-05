/*
** EPITECH PROJECT, 2022
** my_params_to_array
** File description:
** params to array
*/

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param *param = malloc(sizeof(struct info_param) * ac);
    for (int i = 0; i < ac; i += 1) {
        param[i].lenght = my_strlen(av[i]);
        param[i].str = av[i];
        param[i].copy = my_strdup(av[i]);
        param[i].word_array = my_str_to_word_array(av[i]);
    }
    param[ac].str = 0;
    return param;
}
