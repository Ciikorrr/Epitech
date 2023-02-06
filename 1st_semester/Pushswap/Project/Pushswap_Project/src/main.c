/*
** EPITECH PROJECT, 2022
** Start_projet
** File description:
** main
*/


#include <unistd.h>
#include "my.h"
#include "mylist.h"
#include "operations.h"
#include "macros.h"
#include "protos.h"

int main(int argc, char **argv)
{
    if (check_isnum(argc, argv) == ERROR_EPITECH)
        return ERROR_EPITECH;
    if (check_argc(argc) == SUCCESS_EPITECH)
        return SUCCESS_EPITECH;
    s_list *lists = malloc(sizeof(s_list));
    if (lists == NULL)
        return ERROR_EPITECH;
    lists = fill_list(argc, argv, lists);
    if (check_sort(lists->la) == SUCCESS_EPITECH) {
        write(1, "\n", 1);
    } else if (check_sort(lists->la) != SUCCESS_EPITECH && CS) {
        action_sa(lists->la);
        write(1, "sa\n", 3);
    } else {
        lists = make_sort(lists);
        free_all(lists);
        write(1, "\n", 1);
    return SUCCESS_EPITECH;
    }
    return SUCCESS_EPITECH;
}
