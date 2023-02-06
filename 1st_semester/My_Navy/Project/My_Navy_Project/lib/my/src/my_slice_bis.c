/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
int my_strlen(char *str);
int is_num(char c);

void verif_values(int *arr, char *str)
{
    if (arr[0] == '\0')
        arr[0] = 0;
    if (arr[1] == '\0' || arr[1] > my_strlen(str))
        arr[1] = my_strlen(str);
    if (arr[2] == '\0')
        arr[2] = 1;
}

void verif_neg_step_values(int *arr, char *str)
{
    if (arr[0] == '\0')
        arr[0] = my_strlen(str) - 1;
    if (arr[1] == '\0')
        arr[1] = -1;
}

char *get_padding_3(char *slice)
{
    char *r = malloc(sizeof(char) * 4);
    r[0] = 'f';
    r[1] = 'f';
    r[2] = 'f';
    r[3] = '\0';
    int len = my_strlen(slice);
    if (is_num(slice[1]) == 0)
        r[0] = 't';
    if (is_num(slice[len - 2]) == 0)
        r[2] = 't';

    int f_c = 0;
    int idx = 0;

    while (slice[idx++] != ':')
        f_c += 1;

    if (is_num(slice[f_c + 1]) == 0)
        r[1] = 't';
    return r;
}
