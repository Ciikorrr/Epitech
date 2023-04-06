/*
** EPITECH PROJECT, 2023
** prims algo
** File description:
** prims_algorithm
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <time.h>
#include "../include/protos.h"
#include "../include/prims_class.h"
#include <SFML/Graphics.h>
#include <unistd.h>

static void set_all_borders(prims *maze, int x, int y)
{
    maze->base.add_border(&maze->base, (coords_t){x, y + 2});
    maze->base.add_border(&maze->base, (coords_t){x, y - 2});
    maze->base.add_border(&maze->base, (coords_t){x + 2, y});
    maze->base.add_border(&maze->base, (coords_t){x - 2, y});
}

static void set_maze_base(prims *maze, int idx, sfRenderWindow *window)
{
    maze->base.maze[maze->base.list.array[idx].coords.x][maze->base.list.array[idx].coords.y].visited = true;
    maze->base.maze[maze->base.list.array[idx].coords.x][maze->base.list.array[idx].coords.y].cell_case = '*';
    /*
    sfRectangleShape *tmp;
    tmp = sfRectangleShape_create();
    sfRectangleShape_setFillColor(tmp, sfWhite);
    sfRectangleShape_setSize(tmp, (sfVector2f){1920.f / maze->base.width, 1080.f / maze->base.height});
    */
    sfRectangleShape_setPosition(maze->base.pass, (sfVector2f){maze->base.list.array[idx].coords.x * 1920.f / maze->base.width, maze->base.list.array[idx].coords.y * 1080.f / maze->base.height});
    sfRenderWindow_drawRectangleShape(window, maze->base.pass, NULL);
    //sfRectangleShape_destroy(maze->base.pass);
}

static void set_maze_base_border(prims *maze,int idx)
{
    maze->base.add_border(&maze->base, (coords_t){maze->base.list.array[idx].coords.x, maze->base.list.array[idx].coords.y + 2});
    maze->base.add_border(&maze->base, (coords_t){maze->base.list.array[idx].coords.x, maze->base.list.array[idx].coords.y - 2});
    maze->base.add_border(&maze->base, (coords_t){maze->base.list.array[idx].coords.x + 2, maze->base.list.array[idx].coords.y});
    maze->base.add_border(&maze->base, (coords_t){maze->base.list.array[idx].coords.x - 2, maze->base.list.array[idx].coords.y});
}

void window_check_event(sfEvent *event, sfRenderWindow *window, prims *maze)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->type == sfEvtKeyPressed) {
        sfKeyEvent tmp = event->key;
        if (tmp.code == sfKeyQ || tmp.code == sfKeyEscape)
            sfRenderWindow_close(window);
        if (tmp.code == sfKeyS)
            maze->base.show_front *= -1;
    }
}

typedef struct front_s {

    sfRectangleShape *front;
    int x;
    int y;
    sfColor white;

} front_t;

static void loop(prims *maze, int idx, int start_x, int start_y)
{
    sfVideoMode mode = {1920, 1080, 1};
    sfRenderWindow *window;
    sfEvent event;

    window = sfRenderWindow_create(mode, "DANTE", sfResize | sfClose, NULL);
    if (!window)
        exit(88);

    sfRenderWindow_setFramerateLimit(window, 120);

    sfRectangleShape *start;
    start = sfRectangleShape_create();
    sfRectangleShape_setFillColor(start, sfBlue);
    sfRectangleShape_setSize(start, (sfVector2f){1920.f / maze->base.width, 1080.f / maze->base.height});
    sfRectangleShape_setPosition(start, (sfVector2f){start_x * 1920.f / maze->base.width, start_y * 1080.f / maze->base.height});
    sfRenderWindow_drawRectangleShape(window, start, NULL);
    sfRectangleShape_destroy(start);
    while(sfRenderWindow_isOpen(window) && maze->base.list.lenght > -1)
    {
        while(sfRenderWindow_pollEvent(window, &event))
            window_check_event(&event, window, maze);


        sfRenderWindow_display(window);
        if (maze->base.list.lenght > 0)
            idx = rand() % maze->base.list.lenght;
        set_maze_base(maze, idx, window);
        random_neighbours(maze, idx, window);
        set_maze_base_border(maze, idx);
        maze->base.remove_border(&maze->base, idx, window);
        /*
        for (int i = 0; i < maze->base.width; i++)
        {
            for (int j = 0; j < maze->base.height; j++)
            {
                if (i == start_x && j == start_y)
                {
                    sfRectangleShape *start;
                    start = sfRectangleShape_create();
                    sfRectangleShape_setFillColor(start, sfBlue);
                    sfRectangleShape_setOutlineColor(start, sfGreen);
                    sfRectangleShape_setOutlineThickness(start, 1.0f);
                    sfRectangleShape_setSize(start, (sfVector2f){1920.f / maze->base.width, 1080.f / maze->base.height});
                    sfRectangleShape_setPosition(start, (sfVector2f){i * 1920.f / maze->base.width, j * 1080.f / maze->base.height});
                    sfRenderWindow_drawRectangleShape(window, start, NULL);
                    sfRectangleShape_destroy(start);
                    continue;
                }
                if (maze->base.maze[i][j].cell_case == '*')
                {
                    sfRectangleShape *tmp;
                    tmp = sfRectangleShape_create();
                    sfRectangleShape_setFillColor(tmp, sfWhite);
                    sfRectangleShape_setSize(tmp, (sfVector2f){1920.f / maze->base.width, 1080.f / maze->base.height});
                    sfRectangleShape_setPosition(tmp, (sfVector2f){i * 1920.f / maze->base.width, j * 1080.f / maze->base.height});
                    sfRenderWindow_drawRectangleShape(window, tmp, NULL);
                    sfRectangleShape_destroy(tmp);
                    continue;
                }
                for (int k = 0; k < maze->base.list.lenght; k++)
                {
                    sfRectangleShape *temp;
                    temp = sfRectangleShape_create();
                    sfRectangleShape_setFillColor(temp, sfRed);
                    sfRectangleShape_setSize(temp,(sfVector2f){1920.f / maze->base.width, 1080.f / maze->base.height});
                    sfRectangleShape_setPosition(temp, (sfVector2f){maze->base.list.array[k].coords.x * (1920.f / maze->base.width), maze->base.list.array[k].coords.y * (1080.f / maze->base.height)});
                    sfRenderWindow_drawRectangleShape(window, temp, NULL);
                    sfRectangleShape_destroy(temp);
                    continue;
                }
            }
        }
        */
    }
    sleep(3);
}

int prims_maze_generator(int row, int col, bool perfect)
{
    srand(time(NULL));
    prims *maze = new_prims(row, col);
    if (perfect == true)
        maze->base.perfect = true;
    else
        maze->base.perfect = false;
    //int x = 0;
    //int y = 0;
    int x = rand() % row;
    int y = rand() % col;

    maze->base.pass = sfRectangleShape_create();
    maze->base.front = sfRectangleShape_create();

    sfRectangleShape_setFillColor(maze->base.pass, sfWhite);
    sfRectangleShape_setFillColor(maze->base.front, sfRed);

    sfRectangleShape_setSize(maze->base.pass, (sfVector2f){1920.f / maze->base.width, 1080.f / maze->base.height});
    sfRectangleShape_setSize(maze->base.front, (sfVector2f){1920.f / maze->base.width, 1080.f / maze->base.height});

    maze->base.show_front = -1;

    maze->base.maze[x][y].cell_case = '*';
    maze->base.maze[x][y].visited = true;
    set_all_borders(maze, x, y);
    int idx = 0;
    loop(maze, idx, x, y);
    check_even(&maze->base, row, col);
    maze->base.display_maze(&maze->base);
    return 0;
}
