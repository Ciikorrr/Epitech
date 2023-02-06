/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-myls-marius.marolleau
** File description:
** flag_l
*/
#include "protos.h"
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>

void get_right(struct stat entry_file)
{
    my_printf( (S_ISDIR(entry_file.st_mode)) ? "d" : "-");
    my_printf( (entry_file.st_mode & S_IRUSR) ? "r" : "-");
    my_printf( (entry_file.st_mode & S_IWUSR) ? "w" : "-");
    my_printf( (entry_file.st_mode & S_IXUSR) ? "x" : "-");
    my_printf( (entry_file.st_mode & S_IRGRP) ? "r" : "-");
    my_printf( (entry_file.st_mode & S_IWGRP) ? "w" : "-");
    my_printf( (entry_file.st_mode & S_IXGRP) ? "x" : "-");
    my_printf( (entry_file.st_mode & S_IROTH) ? "r" : "-");
    my_printf( (entry_file.st_mode & S_IWOTH) ? "w" : "-");
    my_printf( (entry_file.st_mode & S_IXOTH) ? "x" : "-");
}

void get_owner(struct stat entry_file)
{
    struct passwd *pwd;
    struct group *gp;
    pwd = getpwuid(entry_file.st_uid);
    gp = getgrgid(entry_file.st_gid);
    my_printf(" %s", pwd->pw_name);
    my_printf(" %s", gp->gr_name);
}

int get_info(char *path, int total)
{
    struct stat entry_file;
    int toto = stat(path, &entry_file);
    char *date = ctime(&entry_file.st_mtime);
    total = entry_file.st_blocks;
    get_right(entry_file);
    my_printf(".");
    my_printf(" %d ", entry_file.st_nlink);
    get_owner(entry_file);
    my_printf("\t%d ", entry_file.st_size);
    my_printf("\t%c%c%c%c", date[4], date[5], date[6], date[7]);
    my_printf("\t%c%c", date[8], date[9]);
    my_printf("\t%c%c%c%c%c%c", date[10], date[11], date[12], date[13],
    date[14], date[15]);
    return total;
}

int compare(int argc, DIR *dir, struct dirent *file)
{
    if (argc == 2) {
        while (file != NULL) {
            do_l(file);
        file = readdir(dir);
        }
        return 0;
    }
}

int flag_l(struct dirent *entry, char *path, int argc, char **argv)
{
    char *temp = my_strdup(path);
    int total = 0;
    int type = find_type(path, entry, type);
    if (type == 1) {
        get_info(path, total);
        my_printf("\t%s\n", path);
        return 0;
    }
    total = info_l(total,argc, path, temp);
    my_printf("total %d\n", total / 2);
    free(temp);
}
