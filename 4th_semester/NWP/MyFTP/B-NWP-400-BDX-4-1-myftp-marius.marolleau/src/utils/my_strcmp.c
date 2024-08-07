/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** reproduce a word
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i]) {
            return s1[i] - s2[i];
        }
        if (s1[i] > s2[i]) {
            return s1[i] - s2[i];
        }
        if (s1[i] == s2[i]) {
            i += 1;
        }
    }
    return 0;
}
