/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#ifndef PROTOS_GAME_H_
    #define PROTOS_GAME_H_

int launch_game_loop(int argc, char **argv);
int connect_player_one(void);
int connect_player_two(char *pid);
void display(int letter1, int num1);
int hit_or_not(void);
char *receive_signal(void);

#endif /* PROTOS_GAME_H_ */
