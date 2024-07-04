#include <SFML/Graphics/Font.hpp>

#include "SfmlDisplay.hpp"

Stack::Stack(const int index) {
    this->Shape = sf::RectangleShape();
    this->Title = sf::Text();
    this->Font = sf::Font();
    this->Font.loadFromFile("Assets/ubuntu-mono.ttf");
    this->Title.setFont(this->Font);
    this->Index = index;
}

void Stack::updateStack(const WidgetStack &stack) {
    // this->Shape
    const sf::Vector2f shapeSize(WINDOW_WIDTH - PADDING_X_CARD, CARD_Y_SIZE);
    this->Shape.setSize(shapeSize);
    this->Shape.setPosition(PADDING_X_CARD / 2,
                            PADDING_Y_CARD + ((CARD_Y_SIZE + PADDING_Y_CARD) *
                                              static_cast<float>(Index)));
    this->Shape.setFillColor(sf::Color(107, 82, 12));

    // this->Title
    this->Title.setString(stack.getTitle());
    this->Title.setCharacterSize(15);
    sf::Vector2f shapePos = this->Shape.getPosition();
    this->Title.setPosition(
        shapePos.x + (PADDING_X_CARD + PADDING_X_TITLE_IN_CARD),
        shapePos.y + (PADDING_Y_CARD + PADDING_Y_TITLE_IN_CARD));
    this->Title.setFillColor(sf::Color(222, 222, 222));
    this->Title.setStyle(sf::Text::Regular);
    this->Title.setOutlineThickness(1);

    std::vector<Widget *> widgets = stack.getWidgets();
    float widgetIndex = 0;
    for (Widget *currentWidget : widgets) {
        if (auto textWidget = dynamic_cast<const TextWidget *>(currentWidget)) {
            sf::Text text;

            int spacing = LINE_LENGTH_IN_CHAR -
                          static_cast<int>(textWidget->getTitle().length()) -
                          static_cast<int>(textWidget->getText().length());
            std::string spacePadding;
            for (int i = 1; i <= spacing; i++) {
                spacePadding += " ";
            }

            std::string strText =
                textWidget->getTitle() + spacePadding + textWidget->getText();
            text.setString(strText);
            text.setFont(this->Font);
            text.setString(strText);
            text.setCharacterSize(13);
            text.setFillColor(sf::Color(222, 222, 222));
            text.setPosition(shapePos.x + PADDING_X_TEXT_IN_CARD,
                             shapePos.y + PADDING_Y_TEXT_IN_CARD +
                                 LINE_SPACING_TEXT * widgetIndex);
            this->Text.push_back(text);
            widgetIndex++;
        }
    }
}
