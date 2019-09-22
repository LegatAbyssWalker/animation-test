#ifndef ANIMATION_H
#define ANIMATION_H

#include "SFML/Graphics.hpp"

#include <chrono>
#include <iostream>

class Animation {
	public:
		//Change depending on type of sprite sheet (rows = numbers)
		enum PlayerDirection {
			pUp = 0,
			pLeft = 1,
			pDown = 2, 
			pRight = 3
		};

		enum EnemyDirection {
			eUp = 0,
			eLeft = 1,
			eDown = 2,
			eRight = 3
		};

		Animation(sf::Texture* texture, const sf::Vector2<unsigned>& imageCount, float switchTime);

		void updateAnimation(bool manualAnimation, bool isMoving, std::string type);
		sf::IntRect uvRect;
		bool isMoving = false;

		PlayerDirection pDirection = pUp;
		EnemyDirection eDirection = eUp;

	private:
		const sf::Vector2<unsigned> imageCount;
		sf::Vector2<unsigned> currentImage;

		std::chrono::steady_clock::time_point tp = std::chrono::steady_clock::now();
		float elapsed() {
			return std::chrono::duration<float>(std::chrono::steady_clock::now() - tp).count();
		}
		const float switchTime;
};

#endif