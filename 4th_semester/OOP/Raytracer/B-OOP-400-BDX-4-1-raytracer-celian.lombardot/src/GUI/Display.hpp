/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Display
*/

#pragma once


#include "Renderer.hpp"
#include "Composite.hpp"
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
namespace raytracer {

class Display
{
   public:
    Display(const Display &) = default;
    Display(Display &&) = delete;
    Display &operator=(const Display &) = default;
    Display &operator=(Display &&) = delete;
    Display(Renderer &pRender, bool graphical, Composite composite);
    ~Display() = default;

   protected:
   private:
    Renderer renderer;

    enum eventType {
        camUpadte,
        quit,
        other,
    };

    void createPPM(Composite composite);
    void launchGUI(Composite composite);
    eventType analyseEvent(sf::Event &event, Composite composite);
    void fillImage(sf::Image &img, Composite composite);
    double setRatio(double old, double newRatio, sf::Sprite &toResize);
};
}  // namespace raytracer
