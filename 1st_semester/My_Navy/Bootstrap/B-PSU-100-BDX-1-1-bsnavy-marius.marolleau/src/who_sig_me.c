/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

typedef struct count{
    int count1;
    int count2;
}count_t;

count_t c;

int handler1()
{
    c.count1 += 1;
}

int handler2()
{
    c.count2 += 1;
}

void handler(int num)
{
    if (num == 10)
        c.count1 += 1;
    if (num == 12)
        c.count2 += 1;
    if (num == 3) {
        printf("SIGUSR1 = %d\n", c.count1);
        printf("SIGUSR2 = %d\n", c.count2);
        exit(0);
    }
}

int main(void)
{
    c.count1 = 0;
    c.count2 = 0;
    signal(SIGQUIT, handler);
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    printf("%d\n", getpid());
    while (1) {
        printf("Hello\n");
        sleep(1);
    }
    return 0;
}
