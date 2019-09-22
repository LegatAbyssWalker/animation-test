#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Animation.h"

class Enemy : public Entity {
	public:
		Enemy(sf::Texture* texture, sf::Vector2<unsigned> imageCount, float switchTime, float speed);
		
		void keyboardInput(sf::Keyboard::Key key, bool isPressed);
		void update(bool manualAnimation);
		void setDirection(const Animation::EnemyDirection& eDirection);
		
	private:
		Animation animation;

		bool moving;
		bool up;
		bool left;
		bool down;
		bool right;
};

#endif