/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** rush3
*/

#include <unistd.h>
#include "include/my.h"
#include "include/rush3.h"

void display(int x, int y, int rush);
void display_d(int x, int y);

int test_rush(char *str, int x, int y)
{
    int rush = 0;
    if (str[0] == 'o') {
        rush = 1;
    }
    if (str[0] == '/' || str[0] == '*') {
        rush = 2;
    }
    if (str[0] == 'A') {
        rush = find_rush(str, x, y);
    } else if (str[0] == 'B') {
        display_d(x, y);
        return 0;
    }
    display(x, y, rush);
    return 0;
}

int find_rush(char *str, int x, int y)
{
    int multi = x * y;
    if (y > 2)
        multi = multi + (y - 2);
    int rush = 0;
    int len = 0;
    for (int i = 0; str[i] != '\n'; i += 1) {
        len += 1;
    }
    if (str[len - 1] == 'A') {
        rush = 3;
        return rush;
    }
    if (str[multi] == 'A') {
        rush = 5;
        return rush;
    } else {
        rush = 4;
    }
    return rush;
}

int rush3(char *str)
{
    int x = 0;
    int y = 0;
    for (int i = 0; str[i] != '\n'; i += 1) {
        x += 1;
    }
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '\n') {
            y += 1;
        }
    }
    if (x == 0 || y == 0) {
        write(2, "none\n", 6);
    } else {
        test_rush(str, x, y);
    }
    return 0;
}

int main(void)
{
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len;
    while ((len = read(0, buff + offset, BUFF_SIZE - offset)) > 0) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84);
    rush3(buff);
    return (0);
}
