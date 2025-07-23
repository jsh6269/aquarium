#include <SFML/Graphics.hpp>
#include "FishManager.h"
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Aquarium");
    window.setFramerateLimit(60);

    FishManager manager;
    for (int i = 0; i < 18; ++i) {
        manager.addFish();
    }

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        manager.tick(deltaTime);

        window.clear(sf::Color(135, 206, 250)); // SkyBlue
        manager.render(window);
        window.display();
    }
    return 0;
}
