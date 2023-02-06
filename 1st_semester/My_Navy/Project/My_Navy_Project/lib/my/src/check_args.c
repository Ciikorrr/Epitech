/*
** EPITECH PROJECT, 2023
** check_args
** File description:
** ouais
*/

int is_valid_file(char *filepath);

int check_args(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    if (is_valid_file(argv[1]) == -1)
        return 84;
    return 0;
}
