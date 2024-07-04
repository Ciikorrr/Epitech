#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <list>
#include <memory>

#include "../../../Krell.hpp"

constexpr float WINDOW_WIDTH = 400;
constexpr float WINDOW_HEIGHT = 740;
constexpr float PADDING_X_CARD = 20;
constexpr float PADDING_Y_CARD = 20;
constexpr float PADDING_X_TITLE_IN_CARD = -10;
constexpr float PADDING_Y_TITLE_IN_CARD = -18;
constexpr float PADDING_X_TEXT_IN_CARD = 10;
constexpr float PADDING_Y_TEXT_IN_CARD = 25;
constexpr float LINE_SPACING_TEXT = 13;
constexpr float CARD_Y_SIZE = 100;
constexpr int LINE_LENGTH_IN_CHAR = 51;

class SFMLDisplay final : public Krell::IDisplay {
   public:
    SFMLDisplay();
    void renderLoop(Krell::Core &core) override;

   private:
    std::unique_ptr<sf::RenderWindow> _window;
    enum eventType { NONE, CLOSE_EVENT };

    void initDrawStack(const WidgetStack &stack, int stackIndex);
    void createWindow();
    eventType eventManager();
};

class Stack {
   public:
    sf::RectangleShape Shape;
    sf::Text Title;
    std::list<sf::Text> Text;
    sf::Font Font;

    int Index;

    explicit Stack(int index);
    void updateStack(const WidgetStack &stack);
};
