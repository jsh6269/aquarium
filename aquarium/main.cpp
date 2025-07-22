#include <SFML/Graphics.hpp>
#include "GameController.h"
#include "Fish.h"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Aquarium");
    window.setFramerateLimit(60);

    sf::Texture fishTexture;
    if (!fishTexture.loadFromFile("assets/fish.png"))
        return -1;

    GameController controller;

    int fish_num = 5;
    for (int i = 0; i < fish_num; i++) {
        controller.addObject(std::make_shared<Fish>(fishTexture));
    }

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        controller.tickAll(deltaTime);

        window.clear(sf::Color(180, 225, 255));
        controller.renderAll(window);
        window.display();
    }

    return 0;
}
