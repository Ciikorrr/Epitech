/*
** EPITECH PROJECT, 2023
** count num
** File description:
** ouais
*/

int is_num(char c);

int count_number(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if ((is_num(str[i]) == 0) && (is_num(str[i + 1]) == 84))
            count += 1;
    }
    return count;
}
