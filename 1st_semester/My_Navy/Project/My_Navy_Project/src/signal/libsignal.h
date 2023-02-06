/*
** EPITECH PROJECT, 2022
** myh
** File description:
** ouais
*/
#include <signal.h>
#include "protos_struct.h"

#ifndef LIBAL_H_
    #define LIBAL_H_

void connect_one(int signo, siginfo_t *info, void *context);
int connect_player_one(void);
int connect_player_two(char *pid);
navy_t *decode_signal(navy_t *navy);
navy_t *verif_input(char *line, navy_t *navy);
navy_t *recup_input(navy_t *navy);
navy_t *launch_attack(navy_t *navy);
void receive(int signo, siginfo_t *info, void *context);
navy_t *receive_consequence(navy_t *navy);
int hit_or_not(void);
void signal_hanlder(int num, siginfo_t *info, void *context);
char *receive_signal(void);

#endif /* LIBAL_H_ */
