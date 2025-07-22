#pragma once
#include <SFML/Graphics.hpp>

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void tick(float deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};
