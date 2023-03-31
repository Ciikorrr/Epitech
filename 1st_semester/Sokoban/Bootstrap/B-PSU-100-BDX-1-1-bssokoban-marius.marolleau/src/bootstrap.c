/*
** EPITECH PROJECT, 2022
** B-PSU-100-BDX-1-1-bssokoban-marius.marolleau
** File description:
** bootstrap
*/

#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
int my_strlen(char const *str);


int main(int argc, char **argv) {
 
    WINDOW * window;
    int      ch;
	if (argc != 2) {
		return 84;
	}
	if ( (window = initscr()) == NULL ) {
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(EXIT_FAILURE);
	}

	int x = getmaxx(window);
	int y = getmaxy(window);
	
	noecho();
	keypad(window, TRUE);

	mvwaddstr(window, y/2 , x/2 - my_strlen(argv[1]), argv[1]);
	
	while ( (ch = getch()) != ' ' ) {
	}
	delwin(window);
    refresh();
	return 0;
}