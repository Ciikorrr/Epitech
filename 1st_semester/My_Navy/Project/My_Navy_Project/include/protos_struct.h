/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#ifndef PROTOS_STRUCT_H_
    #define PROTOS_STRUCT_H_

typedef struct navy {
    char **enemy_map;
    char **map;
    char *attack;
    int letter_attack;
    int nb_attack;
    int correct_coo;
    int hit;
    int destroy;
    int win;
    int recive;
}navy_t;

navy_t *receive_consequence(navy_t *navy);
navy_t *check_win(navy_t *navy);
navy_t *shoot(navy_t *navy);
navy_t *decode_signal(navy_t *navy);
navy_t *check_lose(navy_t *navy);
navy_t *launch_attack(navy_t *navy);
int end_game(navy_t *navy);

#endif /* !PROTOS_STRUCT_H_*/
