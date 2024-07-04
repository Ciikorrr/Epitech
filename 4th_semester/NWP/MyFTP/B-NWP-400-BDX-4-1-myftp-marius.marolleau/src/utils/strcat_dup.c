/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdlib.h>
#include <string.h>

char *my_strcat_dup(const char *str1, const char *str2, const char *str3)
{
    int len1 = 0;
    int len2 = 0;
    int len3 = 0;
    char *result = NULL;

    len1 = (str1 != NULL) ? strlen(str1) : 0;
    len2 = (str2 != NULL) ? strlen(str2) : 0;
    len3 = (str3 != NULL) ? strlen(str3) : 0;
    result = malloc(len1 + len2 + len3 + 1);
    if (result == NULL)
        return NULL;
    if (str1 != NULL)
        strcpy(result, str1);
    if (str2 != NULL)
        strcat(result, str2);
    if (str3 != NULL)
        strcat(result, str3);
    return result;
}
