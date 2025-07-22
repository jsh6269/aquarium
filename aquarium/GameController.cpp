#include "GameController.h"

void GameController::addObject(std::shared_ptr<GameObject> obj) {
    objects.push_back(obj);
}

void GameController::tickAll(float deltaTime) {
    for (auto& obj : objects) {
        obj->tick(deltaTime);
    }
}

void GameController::renderAll(sf::RenderWindow& window) {
    for (auto& obj : objects) {
        obj->render(window);
    }
}
