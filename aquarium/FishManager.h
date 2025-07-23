#pragma once
#include "Fish.h"
#include <vector>
#include <memory>

class FishManager {
public:
    void addFish();
    void tick(float deltaTime);
    void render(sf::RenderWindow& window);

private:
    std::vector<std::shared_ptr<Fish>> fishes;
};
