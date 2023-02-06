/*
** EPITECH PROJECT, 2023
** slicer
** File description:
** ouais
*/

#include <stdlib.h>
#include <stdio.h>

int my_special_getnbr(char *str, int *index);
int my_strlen(char *str);
int count_number(char *str);
int is_num(char c);
void init_start(char *slice, int *start, int *idx);
void init_end(char *slice, int *end, int *idx);
void init_step(char *slice, int *step, int *idx);

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

void verif_values(int *arr, char *str)
{
    if (arr[0] == '\0')
        arr[0] = 0;
    if (arr[1] == '\0' || arr[1] > my_strlen(str))
        arr[1] = my_strlen(str);
    if (arr[2] == '\0')
        arr[2] = 1;
    if (arr[0] < 0)
        arr[0] = my_strlen(str) + arr[0];
    if (arr[1] < 0)
        arr[1] = my_strlen(str) + arr[1];
}

void verif_neg_step_values(int *arr, char *str)
{
    if (arr[1] < 0)
        arr[1] = my_strlen(str) + arr[1];
    if (arr[0] < 0)
        arr[0] = my_strlen(str) + arr[0];
    if (arr[0] == '\0' || arr[0] > my_strlen(str))
        arr[0] = my_strlen(str) - 1;
    if (arr[1] == '\0')
        arr[1] = -1;
}

char *slicing(char *str, int *arr)
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
    if (*str == '\0' || *slice == '\0')
        return NULL;
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
    return slicing(str, arr);
}
