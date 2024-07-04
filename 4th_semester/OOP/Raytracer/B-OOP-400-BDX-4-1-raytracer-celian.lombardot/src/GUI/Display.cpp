/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Display
*/

#include "Display.hpp"

#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <chrono>
#include <cstddef>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <sstream>

#include "Renderer.hpp"

raytracer::Display::Display(
    Renderer &pRender, bool graphical,
    Composite composite)
    : renderer(pRender)
{
    if (graphical)
        launchGUI(composite);
    else
        createPPM(composite);
};

void raytracer::Display::createPPM(
    Composite composite)
{
    std::vector<math::Color> image = renderer.render(composite.getShapes());
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm *localTime = std::localtime(&currentTime);
    std::ostringstream oss;
    oss << std::put_time(localTime, "%Y-%m-%d-%H-%M-%S");

    std::ofstream outFile("out-" + oss.str() + ".ppm");
    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open file out.ppm" << std::endl;
        return;
    }
    outFile << "P3\n"
            << renderer.camWidth() << ' ' << renderer.camHeight() << "\n255\n";
    for (const auto &c : image) {
        c.writeColor(outFile);
    }
    outFile.close();
}

raytracer::Display::eventType raytracer::Display::analyseEvent(
    sf::Event &event, Composite composite)
{
    if (event.type == sf::Event::Closed)
        return quit;

    if (event.type != sf::Event::KeyPressed)
        return other;
    switch (event.key.code) {  // NOLINT
        case sf::Keyboard::Z:
            renderer.moveCam({0, 0, 0.5});
            break;
        case sf::Keyboard::S:
            renderer.moveCam({0, 0, -0.5});
            break;
        case sf::Keyboard::Q:
            renderer.moveCam({-0.5, 0, 0});
            break;
        case sf::Keyboard::D:
            renderer.moveCam({0.5, 0, 0});
            break;
        case sf::Keyboard::LShift:
            renderer.moveCam({0, -0.5, 0});
            break;
        case sf::Keyboard::Space:
            renderer.moveCam({0, 0.5, 0});
            break;
        case sf::Keyboard::Up:
            renderer.rotateCam({0, 5, 0});
            break;
        case sf::Keyboard::Down:
            renderer.rotateCam({0, -5, 0});
            break;
        case sf::Keyboard::Left:
            renderer.rotateCam({5, 0, 0});
            break;
        case sf::Keyboard::Right:
            renderer.rotateCam({-5, 0, 0});
            break;
        case sf::Keyboard::Enter:
            renderer.setRatio(1);
            createPPM(composite);
            return other;
        default:
            return other;
    }
    return camUpadte;
}

void raytracer::Display::fillImage(
    sf::Image &img, Composite composite)
{
    std::vector<math::Color> image = renderer.render(composite);
    int px = 0;

    for (size_t i = 0; double(i) < renderer.camHeight(); ++i) {
        for (size_t j = 0; double(j) < renderer.camWidth(); ++j) {
            img.setPixel(j, i, image.at(px).asSfColor());
            px += 1;
        }
    }
}

double raytracer::Display::setRatio(
    double old, double newRatio, sf::Sprite &toResize)
{
    if (newRatio < 1)
        newRatio = 1;
    auto r = float(newRatio / old);

    renderer.setRatio(1 / newRatio);
    toResize.scale(r, r);
    return newRatio;
}

void raytracer::Display::launchGUI(
    Composite composite)
{
    sf::RenderWindow win{
        sf::VideoMode(renderer.camWidth(), renderer.camHeight()), "RayTracer",
        sf::Style::Close};
    std::vector<sf::Event> events = {};
    sf::Event event{};
    sf::Image image;
    image.create(renderer.camWidth(), renderer.camHeight(), sf::Color::Black);
    double ratio = 1;
    sf::Texture te;
    fillImage(image, composite);
    te.loadFromImage(image);
    sf::Sprite sp{te};

    double newRatio = 1;
    while (true) {
        win.clear();
        win.draw(sp);
        win.display();
        newRatio = ratio - 1;
        if (win.pollEvent(event)) {
            auto res = analyseEvent(event, composite);
            if (res == quit)
                break;
            if (res != camUpadte)
                continue;
            newRatio = 7;
        }
        ratio = setRatio(ratio, newRatio, sp);
        fillImage(image, composite);
        te.loadFromImage(image);
        sp.setTexture(te);
    }
}
