/*
** EPITECH PROJECT, 2023
** rle
** File description:
** music usage
*/

#include "../include/protos.h"
#include <stdio.h>
#include "../../include/my.h"
#include <unistd.h>

char *rle_algorithm(char *str)
{
    int len = my_strlen(str);
    char *occurences = malloc(sizeof(char) * (len * 2 + 1));
    char *result = malloc(sizeof(char) * (len * 2 + 1));
    int *arr = malloc(sizeof(int) * len);
    int sequence = 0;
    int j = 0;
    int k = 0;
    for (int i = 0; i < len; i += 1) {
        occurences[j++] = str[i];
        sequence = 1;

        while (str[i] == str[i + 1] && i + 1 < len) {
            sequence += 1;
            i += 1;
        }
        arr[k] = sequence;
        k += 1;
    }
    int idx = 0;
    for (int i = 0; i < (k * 2); i += 2) {
        result[i] = occurences[idx];
        result[i + 1] = arr[idx] + 48;
        idx += 1;
    }
    return result;
}

char *decompress_rle(char *str)
{
    int rLen = 0;
    int len = my_strlen(str);
    int count = 0;
    int idx = 0;
    for (int i = 0; i < len; i += 2)
        rLen += (str[i + 1] - 48);
    char *result = malloc(sizeof(char) * (rLen + 1));
    result[rLen] = '\0';
    for (int i = 0; i < len; i += 2) {
        count = 0;
        while (count < str[i + 1] - 48) {
            result[idx++] = str[i];
            count += 1;
        }
    }
    return result;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    char *test = get_script(argv[1]);
    test = rle_algorithm(test);
    printf("%s", test);
}
