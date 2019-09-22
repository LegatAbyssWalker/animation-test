#include "Player.h"

#include "MoreInfo.h"


Player::Player(sf::Texture* texture, sf::Vector2<unsigned> imageCount, float switchTime, float speed) 
	: Entity(*texture), animation{ texture, imageCount, switchTime } {

	this->speed = speed;

	entity.setOrigin(entity.getGlobalBounds().width / 2, entity.getGlobalBounds().height / 2);
}

void Player::keyboardInputs(sf::Keyboard::Key key, bool isPressed) {
	if (key == sf::Keyboard::W) { up = isPressed; }
	if (key == sf::Keyboard::A) { left = isPressed; }
	if (key == sf::Keyboard::S) { down = isPressed; }
	if (key == sf::Keyboard::D) { right = isPressed; }
}

void Player::updatePlayer(bool manualAnimation) {
	//Movement/Animation
	sf::Vector2<float> playerMovement(0.f, 0.f);
	
	if      (up)    { playerMovement.y -= speed; setDirection(Animation::PlayerDirection::pUp);    moving = true; }
	else if (left)  { playerMovement.x -= speed; setDirection(Animation::PlayerDirection::pLeft);  moving = true; }
	else if (down)  { playerMovement.y += speed; setDirection(Animation::PlayerDirection::pDown);  moving = true; }
	else if (right) { playerMovement.x += speed; setDirection(Animation::PlayerDirection::pRight); moving = true; }
	else { setDirection(Animation::PlayerDirection::pDown); moving = false; }

	animation.updateAnimation(manualAnimation, moving, "Player");
	entity.setTextureRect(animation.uvRect);
	entity.move(playerMovement);
}

void Player::setDirection(const Animation::PlayerDirection& pDirection) {
	animation.pDirection = pDirection;
}


void Player::updateBorderBounds() {
	//Entity cannot go through the borders of the screen
	if (getX() <= SCREEN_WIDTH * 0) { setPosition(sf::Vector2<float>(getX() + PLAYER_SPEED, getY())); } //Left Side
	if (getX() >= SCREEN_WIDTH)		{ setPosition(sf::Vector2<float>(getX() - PLAYER_SPEED, getY())); } //Right Side
}
