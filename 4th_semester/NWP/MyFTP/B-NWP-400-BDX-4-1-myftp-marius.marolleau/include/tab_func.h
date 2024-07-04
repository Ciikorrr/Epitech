/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myftp-marius.marolleau
** File description:
** tab_func
*/

#ifndef TAB_FUNC_H_
    #define TAB_FUNC_H_
    #include "myftp.h"

int func_user(myftp_t *myftp, char **tab_cmd, int i);
int func_pass(myftp_t *myftp, char **tab_cmd, int i);
int func_cwd(myftp_t *myftp, char **tab_cmd, int i);
int func_cdup(myftp_t *myftp, char **tab_cmd, int i);
int func_quit(myftp_t *myftp, char **tab_cmd, int i);
int func_dele(myftp_t *myftp, char **tab_cmd, int i);
int func_pwd(myftp_t *myftp, char **tab_cmd, int i);
int func_pasv(myftp_t *myftp, char **tab_cmd, int i);
int func_port(myftp_t *myftp, char **tab_cmd, int i);
int func_noop(myftp_t *myftp, char **tab_cmd, int i);
int func_help(myftp_t *myftp, char **tab_cmd, int i);
int func_retr(myftp_t *myftp, char **tab_cmd, int i);
int func_stor(myftp_t *myftp, char **tab_cmd, int i);
int func_list(myftp_t *myftp, char **tab_cmd, int i);
int func_syst(myftp_t *myftp, char **tab_cmd, int i);

static func_t tab_func[] = {
    {"USER", &func_user, "Specify user for authentication"},
    {"PASS", &func_pass, "Specify password for authentication"},
    {"CWD", &func_cwd, "Change working directory"},
    {"CDUP", &func_cdup, "Change working directory to parent directory"},
    {"QUIT", &func_quit, "Disconnection"},
    {"DELE", &func_dele, "Delete file on the server"},
    {"PWD", &func_pwd, "Print working directory"},
    {"PASV", &func_pasv, "Enable \"passive\" mode for data transfer"},
    {"PORT", &func_port, "Enable \"active\" mode for data transfer"},
    {"HELP", &func_help, "List available commands"},
    {"NOOP", &func_noop, "Do nothing"},
    {"RETR", &func_retr, "Download file from server to client"},
    {"STOR", &func_stor, "Upload file from client to server"},
    {"LIST", &func_list, "List files in the current working directory"},
    {"SYST", &func_syst, "system return"}
};
    #define TAB_SIZE 15

#endif /* !TAB_FUNC_H_ */
