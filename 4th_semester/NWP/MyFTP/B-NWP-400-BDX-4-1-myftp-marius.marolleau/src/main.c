/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** main
*/
#include "../include/macros.h"
#include "../include/error_handling.h"
#include "../include/myftp.h"

int main(int args, char const *argv[])
{
    int res = check_args(args, argv);
    myftp_t myftp = {0};

    if (res == ERROR)
        return ERROR;
    if (res == EXIT)
        return SUCCESS;
    if (init_server_struct(argv, &myftp) == ERROR)
        return ERROR;
    if (init_server(&myftp) == ERROR)
        return ERROR;
    if (myftp_func(&myftp) == ERROR)
        return ERROR;
    if (free_all(&myftp) == ERROR)
        return ERROR;
    return SUCCESS;
}
