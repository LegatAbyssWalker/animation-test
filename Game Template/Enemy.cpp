#include "Enemy.h"
#include "MoreInfo.h"

Enemy::Enemy(sf::Texture* texture, sf::Vector2<unsigned> imageCount, float switchTime, float speed)
	: Entity(*texture), animation(texture, imageCount, switchTime) {

	entity.setOrigin(entity.getGlobalBounds().width / 2, entity.getGlobalBounds().height / 2);
}

void Enemy::keyboardInput(sf::Keyboard::Key key, bool isPressed) {
	if (key = sf::Keyboard::Up) { up = isPressed; }
	if (key = sf::Keyboard::Left) { left = isPressed; }
	if (key = sf::Keyboard::Down) { down = isPressed; }
	if (key = sf::Keyboard::Right) { right = isPressed; }
}

void Enemy::update(bool manualAnimation) {
	if (up)         { setDirection(Animation::EnemyDirection::eUp); moving = true; }
	else if (left)  { setDirection(Animation::EnemyDirection::eLeft); moving = true; }
	else if (down)  { setDirection(Animation::EnemyDirection::eDown); moving = true; }
	else if (right) { setDirection(Animation::EnemyDirection::eRight); moving = true; }
	else { setDirection(Animation::EnemyDirection::eDown); moving = false; }

	animation.updateAnimation(manualAnimation, moving, "Enemy");
	entity.setTextureRect(animation.uvRect);
}

void Enemy::setDirection(const Animation::EnemyDirection& eDirection) {
	animation.eDirection = eDirection;
}
