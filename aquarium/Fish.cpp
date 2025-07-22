#include "Fish.h"

Fish::Fish(const sf::Texture& texture) {
    sprite.setTexture(texture);
    sprite.setScale(0.1f, 0.1f);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);

    float spriteWidth = sprite.getGlobalBounds().width;
    float spriteHeight = sprite.getGlobalBounds().height;

    float x = static_cast<float>(std::rand() % static_cast<int>(800 - spriteWidth)) + spriteWidth / 2.f;

    float minY = spriteHeight / 2.f;
    float maxY = 600.f - spriteHeight / 2.f;
    float y = minY + static_cast<float>(std::rand() % static_cast<int>(maxY - minY));

    sprite.setPosition(x, y);
}

void Fish::tick(float deltaTime) {
    sf::Vector2f pos = sprite.getPosition();
    float width = sprite.getGlobalBounds().width;

    if (movingRight) {
        pos.x += speed * deltaTime;
        if (pos.x + width / 2 >= 800) {
            movingRight = false;
            sprite.setScale(-0.1f, 0.1f);  // 좌우 반전
        }
    }
    else {
        pos.x -= speed * deltaTime;
        if (pos.x - width / 2 <= 0) {
            movingRight = true;
            sprite.setScale(0.1f, 0.1f);   // 원래 방향
        }
    }

    sprite.setPosition(pos);
}

void Fish::render(sf::RenderWindow& window) {
    window.draw(sprite);
}
