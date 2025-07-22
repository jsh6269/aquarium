#include "Fish.h"
#include <sstream>
#include <iomanip>

Fish::Fish() {
    int index = std::rand() % 24;  // 0 ~ 23
    std::stringstream ss;
    ss << "assets/" << std::setw(3) << std::setfill('0') << index << ".png";
    if (!texture.loadFromFile(ss.str())) {
        throw std::runtime_error("Failed to load texture: " + ss.str());
    }
    sprite.setTexture(texture);
    sprite.setScale(scale, scale);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);

    float spriteWidth = sprite.getGlobalBounds().width;
    float spriteHeight = sprite.getGlobalBounds().height;
    float x = spriteWidth / 2 + static_cast<float>(std::rand() % static_cast<int>(800 - spriteWidth / 2));
    float y = static_cast<float>(std::rand() % static_cast<int>(600 - spriteHeight / 4));
    sprite.setPosition(x, y);

    movingRight = std::rand() % 2 == 0;
    sprite.setScale(movingRight ? scale : -scale, scale);
}

void Fish::tick(float deltaTime) {
    timeAccumulator += deltaTime;
    if (timeAccumulator > fluctuationInterval) {
        speed = 30.f + static_cast<float>(std::rand() % 81); // 30~110
        timeAccumulator = 0.f;
    }

    // 일정 확률로 방향 전환
    if (std::rand() % 300 == 0) {
        movingRight = !movingRight;
        sprite.setScale(movingRight ? scale : -scale, scale);
    }

    sf::Vector2f pos = sprite.getPosition();
    float width = sprite.getGlobalBounds().width;

    if (movingRight) {
        pos.x += speed * deltaTime;
        if (pos.x + width / 2 >= 800) {
            movingRight = false;
            sprite.setScale(-scale, scale);
        }
    }
    else {
        pos.x -= speed * deltaTime;
        if (pos.x - width / 2 <= 0) {
            movingRight = true;
            sprite.setScale(scale, scale);
        }
    }
    sprite.setPosition(pos);
}

void Fish::render(sf::RenderWindow& window) {
    window.draw(sprite);
}
