/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-marius.marolleau
** File description:
** handleInputsSFML
*/

#include "../../Game/IGameModule.hpp"

extern "C" std::string handleInputSFML(IGameModule &snake)
{
    sf::Event event;

    while (snake.getWindowSFML()->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                return "SHUTDOWN";
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        return "EXIT_GAME";
                    case sf::Keyboard::S:
                        return "arcade_sdl2.so";
                    case sf::Keyboard::N:
                        return "arcade_ncurses.so";
                    case sf::Keyboard::BackSpace:
                        return "SHUTDOWN";
                    case sf::Keyboard::Up:
                        if (snake.getSnakeSize() != 0 && snake.getSnakeDir() == DOWN)
                            break;
                        snake.setSnakeDir(UP);
                        break;
                    case sf::Keyboard::Left:
                        if (snake.getSnakeSize() != 0 && snake.getSnakeDir() == RIGHT)
                            break;
                        snake.setSnakeDir(LEFT);
                        break;
                    case sf::Keyboard::Down:
                        if (snake.getSnakeSize() != 0 && snake.getSnakeDir() == UP)
                            break;
                        snake.setSnakeDir(DOWN);
                        break;
                    case sf::Keyboard::Right:
                        if (snake.getSnakeSize() != 0 && snake.getSnakeDir() == LEFT)
                            break;
                        snake.setSnakeDir(RIGHT);
                        break;
                }
        }
    }
    return "";
}