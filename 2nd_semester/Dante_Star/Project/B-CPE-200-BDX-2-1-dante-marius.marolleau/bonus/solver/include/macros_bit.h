/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#ifndef MACROS_BIT_H_

    #define MACROS_BIT_H_

    #define WALL 0b10000000
    #define EXPLORED 0b01000000
    #define PATH 0b00100000
    #define LIBRE 0b00000000
    #define IS_WALL(cell) (cell & WALL)
    #define IS_EXPLORE(cell) (cell & EXPLORED)
    #define IS_PATH(cell) (cell & PATH)

    #define NORTH 0b00
    #define SOUTH 0b01
    #define EAST 0b10
    #define WEST 0b11

    #define PREV 0b00001100

    #define IS_NORTH(cell) (cell >> 2 & NORTH)
    #define IS_SOUTH(cell) (cell >> 2 & SOUTH)
    #define IS_EAST(cell) (cell >> 2 & EAST)
    #define IS_WEST(cell) (cell >> 2 & WEST)

    #define CAN_BE_NEXT(cell) (cell & (WALL | EXPLORED))
    #define GET_PREV(cell) ((cell & PREV) >> 2)


#endif /* MACROS_BIT_H */
