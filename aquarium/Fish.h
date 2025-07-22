#pragma once
#include "GameObject.h"

class Fish : public GameObject {
public:
    Fish(const sf::Texture& texture);
    void tick(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Sprite sprite;
    float speed = 100.0f;
    bool movingRight = true;
};
