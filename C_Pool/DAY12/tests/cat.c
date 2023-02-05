/*
** EPITECH PROJECT, 2022
** my_readline
** File description:
** read a file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void control(int argc, int buf)
{
    if (argc == 1) {
        while (1) {
            read(0, buf, 30000);
            write(1, buf, my_strlen(buf));
        }
    }
}

int cat(int argc, char **argv)
{
    int fd;
    int buf[30000];
    int size;
    for (int i = 1; i < argc; i += 1) {
        fd = open(argv[i], 0);
        if (fd == -1) {
            write(2, "Error, file not found",21);
            my_putchar('\n');
            return -84;
        }
        size = read(fd, buf, 30000);
        write(1, buf, my_strlen(buf));
        my_putchar('\n');
    }
    control(argc, buf);
    my_putchar('\n');
    return 0;
}
