/*
** EPITECH PROJECT, 2023
** slicer
** File description:
** ouais
*/

#include <stdlib.h>

int my_special_getnbr(char *str, int *index);
int my_strlen(char *str);
int count_number(char *str);
int is_num(char c);
void verif_values(int *arr, char *str);
void verif_neg_step_values(int *arr, char *str);
char *get_padding_3(char *slice);

static void init_start(char *slice, int *start, int *idx)
{
    *start = my_special_getnbr(slice, idx);
}

static void init_end(char *slice, int *end, int *idx)
{
    *end = my_special_getnbr(slice, idx);
}

static void init_step(char *slice, int *step, int *idx)
{
    *step = my_special_getnbr(slice, idx);
}

static char *slicing(char *str, int *arr)
{
    char *result;
    int idx = 0;
    if (arr[2] < 0) {
        verif_neg_step_values(arr, str);
        result = malloc(sizeof(char) * ((arr[0] - arr[1]) + 1));
        for (int i = arr[0]; i > arr[1]; i += arr[2])
            result[idx++] = str[i];
    } else {
        verif_values(arr, str);
        result = malloc(sizeof(char) * ((arr[1] - arr[0]) + 1));
        for (int i = arr[0]; i < arr[1]; i += arr[2])
            result[idx++] = str[i];
    }
    return result;
}

char *my_slice(char *str, char *slice)
{
    void (*f[3])(char *str, int *node, int *idx) =
    {&init_start, &init_end, &init_step};
    char *pad = malloc(sizeof(char) * 3);
    pad = get_padding_3(slice);
    int arr[3] = {'\0', '\0', '\0'};
    int idx = 0;
    int temp = 0;
    for (int i = 0; pad[i] != '\0'; i += 1) {
        if (pad[i] == 'f')
            temp = my_special_getnbr(slice, &idx);
        else
            f[i](slice, &arr[i], &idx);
    }
    free(pad);
    str = slicing(str, arr);
    return str;
}
