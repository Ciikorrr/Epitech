/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** myftp_func
*/
#include "../include/myftp.h"
#include "../include/macros.h"

int myftp_func(myftp_t *myftp)
{
    while (1) {
        if (test_new_client(myftp) == ERROR)
            return ERROR;
        if (select_client(myftp) == ERROR)
            return ERROR;
    }
}
