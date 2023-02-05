/*
** EPITECH PROJECT, 2022
** my_readline
** File description:
** read a file
*/

#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

void control(int argc, int buf)
{
    if (argc == 1) {
        while (1) {
            read(0, buf, 30000);
            write(1, buf, my_strlen(buf));
        }
    }
}

int my_cat(int argc, char **argv)
{
    int fd;
    int buf[30000];
    int size;
    for (int i = 1; i < argc; i += 1) {
        fd = open(argv[i], 0);
        if (fd == -1) {
            errno2(errno, argv[i]);
            continue;
        }
        size = read(fd, buf, 30000);
        write(1, buf, my_strlen(buf));
    }
    control(argc, buf);
    my_putchar('\n');
    return 0;
}

void my_errno(int erreur)
{
    if (erreur == ENOENT) {
        write(2, ": No such file or directory", 27);
    } else if (erreur == EACCES) {
        write(2, ": Permission denied", 20);
    } else {
        write(2, ": Is a directory", 14);
    }
}
int errno2(int erreur, char *argv)
{
    write(2, "cat: ", 5);
    if (erreur = EPIPE) {
        write(2, "write error: Broken pipe", 11);
        my_putchar('\n');
        return 0;
    }
    if (erreur = ESTRPIPE) {
        write(2, "Streams pipe error", 18);
        my_putchar('\n');
        return 0;
    }
    write(2, argv, my_strlen(argv));
    my_errno(erreur);
    if (erreur == ENOTDIR) {
        write(2, ": Not a directory", 15);
    }
    my_putchar('\n');
    return 0;
}
