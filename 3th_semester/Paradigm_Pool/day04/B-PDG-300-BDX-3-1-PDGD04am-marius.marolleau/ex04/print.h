/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercise 04
*/

#pragma once

void print_normal(const char *str);
void print_reverse(const char *str);
void print_upper(const char *str);
void print_42(const char *str);


typedef enum action_e {
    PRINT_NORMAL,
    PRINT_REVERSE,
    PRINT_UPPER,
    PRINT_42,
    PRINT_COUNT /* Number of actions */
} action_t;

typedef struct tab {
    action_t action;
    void (*function)(const char *str);
}tab_t;

tab_t print[] = {
    {PRINT_NORMAL, &print_normal},
    {PRINT_REVERSE, &print_reverse},
    {PRINT_UPPER, &print_upper},
    {PRINT_42, &print_42},
};
    #define TAB_SIZE 4
