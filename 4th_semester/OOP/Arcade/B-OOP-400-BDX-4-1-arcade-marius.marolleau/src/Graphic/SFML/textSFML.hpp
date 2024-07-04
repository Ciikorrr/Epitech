/*
** EPITECH PROJECT, 2024
** test_SFML
** File description:
** Button
*/

#ifndef textSFML_HPP_
#define textSFML_HPP_
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

class textSFML {
    public:
        textSFML(int x, int y, float width, float height, std::string text, std::unique_ptr<sf::RenderWindow> &window, int textSize);
        textSFML(int x, int y, float width, float height, std::string text, std::unique_ptr<sf::RenderWindow> &window, int textSize, const char *font);
        ~textSFML() {};
        sf::Text &getText()
        {
            return libText;
        }
    protected:
    private:
        sf::Font font;
        sf::Text libText;
};

#endif /* !BUTTON_HPP_ */
