/*
** EPITECH PROJECT, 2024
** B-NWP-400-BDX-4-1-myteams-adam.de-lacheisserie-levy
** File description:
** code_create
*/

#include <dlfcn.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "../../../libs/myteams/logging_client.h"
#include "../../../include/macros.h"

int code_create_team(char **cmd)
{
    client_event_team_created(cmd[1], cmd[2], cmd[3]);
    return 0;
}

int code_create_channel(char **cmd)
{
    client_event_channel_created(cmd[1], cmd[2], cmd[3]);
    return 0;
}

static time_t fill_struct_info(int *date, struct tm *timeinfo)
{
    timeinfo->tm_wday = 0;
    timeinfo->tm_mday = date[0];
    timeinfo->tm_hour = date[1];
    timeinfo->tm_min = date[2];
    timeinfo->tm_sec = date[3];
    timeinfo->tm_year = date[4] - 1900;
    timeinfo->tm_isdst = -1;
    return mktime(timeinfo);
}

time_t convert_str_to_time(char *time_str)
{
    struct tm timeinfo;
    char weekday[4];
    char month[4];
    int date[5];
    const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    sscanf(time_str, "%3s %3s %d %d:%d:%d %d",
    weekday, month, &date[0], &date[1], &date[2], &date[3], &date[4]);
    for (int i = 0; i < 12; ++i) {
        if (strcmp(month, months[i]) == 0) {
            timeinfo.tm_mon = i;
            break;
        }
    }
    return fill_struct_info(date, &timeinfo);
}

int code_create_thread(char **cmd)
{
    client_event_thread_created
    (cmd[1], cmd[2], convert_str_to_time(cmd[3]), cmd[4], cmd[5]);
    return 0;
}

int code_create_comment(char **cmd)
{
    client_event_thread_reply_received
    (cmd[1], cmd[2], cmd[3], cmd[4]);
    return SUCCESS;
}
