/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** myftp
*/

#ifndef MYFTP_H_
    #define MYFTP_H_
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/time.h>
    #include <sys/select.h>
    #include <stdbool.h>

    #define MAX_PATH 4096

typedef struct client_tab_s {
    int fd_client;
    char user_buf[BUFSIZ];
    int pasv_fd;
    int list_fd;
    char *path;
    struct sockaddr_in client;
    struct sockaddr_in data_stct;
    bool pasv_mode;
    bool actv_mode;
    bool pass;
    bool user;
} client_tab_t;

typedef struct myftp_s {
    int nb_client;
    int fd_clt;
    int server_fd;
    int port_use;
    char const *path;
    fd_set tab_fd;
    struct timeval tv;
    struct sockaddr_in server_struct;
    client_tab_t **tab_clt;
} myftp_t;

typedef struct tab_function {
    char *command;
    int (*function)(myftp_t *myftp, char **tab_cmd, int index_clt);
    char *help;
}func_t;

    #define TAB_SIZE 15


int init_server_struct(char const *argv[], myftp_t *myftp);
int init_server(myftp_t *myftp);
int myftp_func(myftp_t *myftp);
int test_new_client(myftp_t *myftp);
int free_all(myftp_t *myftp);
int select_client(myftp_t *myftp);
char **my_str_to_word_array_separator(char *str, char *separator);
void free_tab(char **tab);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat_dup(const char *str1, const char *str2, const char *str3);
char *get_path(char const *src);
int remove_first_client(myftp_t *myftp);
bool check_mode(client_tab_t *clt);
bool check_list_fd(client_tab_t *clt);
int check_file_exist(char *filepath, client_tab_t *clt);

#endif /* !MYFTP_H_ */
