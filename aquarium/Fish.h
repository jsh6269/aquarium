#pragma once
#include "GameObject.h"
#include <memory>
#include <cstdlib>
#include <ctime>

class Fish : public GameObject {
public:
    Fish();
    void tick(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Texture texture;
    sf::Sprite sprite;
    float speed = 100.f;
    bool movingRight = true;
    float timeAccumulator = 0.f;
    float fluctuationInterval = 1.0f;
    float scale = 0.8f;
};
