/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** copy n letter
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int e = 0;
    int t = 0;
    int i = 0;
    for (; src[i] != '\0'; i += 1) {
        t += 1;
    }
    for (;e < n; e += 1) {
        if (n > t) {
            char mem = src[e];
            dest[e] = mem;
            dest[t] = '\0';
        }
        char mem = src[e];
        dest[e] = mem;
    }
    return dest;
}
