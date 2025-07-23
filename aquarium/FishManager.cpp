#include "FishManager.h"
#include <sstream>
#include <iomanip>

void FishManager::addFish() {
    int index = std::rand() % 24;  // 0 ~ 23
    std::stringstream ss;
    ss << "assets/" << std::setw(3) << std::setfill('0') << index << ".png";
    fishes.push_back(std::make_shared<Fish>(ss.str()));
}

void FishManager::tick(float deltaTime) {
    for (auto& fish : fishes) {
        fish->tick(deltaTime);
    }
}

void FishManager::render(sf::RenderWindow& window) {
    for (auto& fish : fishes) {
        fish->render(window);
    }
}
