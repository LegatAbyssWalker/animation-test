#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"

#include "Entity.h"
#include "Animation.h"

#include <iostream>
#include <chrono>

class Player : public Entity {
public:
		Player(sf::Texture* texture, sf::Vector2<unsigned> imageCount, float switchTime, float speed);

		void keyboardInputs(sf::Keyboard::Key key, bool isPressed);
		void updatePlayer(bool manualAnimation);
		void setDirection(const Animation::PlayerDirection& direction);
		void updateBorderBounds();

	private:
		Animation animation;
		float speed;

		bool isOnGround;
		bool up = false;
		bool left = false;
		bool down = false;
		bool right = false;
		bool moving = false;
};

#endif