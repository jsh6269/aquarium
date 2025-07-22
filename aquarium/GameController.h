#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"

class GameController {
public:
    void addObject(std::shared_ptr<GameObject> obj);
    void tickAll(float deltaTime);
    void renderAll(sf::RenderWindow& window);

private:
    std::vector<std::shared_ptr<GameObject>> objects;
};
