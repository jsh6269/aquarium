#include "FishManager.h"

void FishManager::addFish(const std::shared_ptr<Fish>& fish) {
    fishes.push_back(fish);
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
