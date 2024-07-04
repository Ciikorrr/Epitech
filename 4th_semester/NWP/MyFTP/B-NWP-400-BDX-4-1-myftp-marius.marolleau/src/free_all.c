/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** free_all
*/
#include <stdlib.h>
#include "../include/myftp.h"
#include "../include/macros.h"

int free_all(myftp_t *myftp)
{
    if (!myftp->tab_clt) {
        for (int i = 0; !myftp->tab_clt[i]; i++) {
            free(myftp->tab_clt[i]);
        }
        free(myftp->tab_clt);
    }
    return SUCCESS;
}
