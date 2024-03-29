#include "PlayingState.h"

#include "State.h"
#include "StateMachine.h"
class StateMachine;

#include "MoreInfo.h"

PlayingState::PlayingState(StateMachine& machine, sf::RenderWindow& window, bool replace)
	: State{ machine, window, replace },
	versionText(SCREEN_WIDTH - 100, SCREEN_HEIGHT - 30, 25, ARIAL_FONT, "Version 0.0", sf::Color(255, 255, 0)) {


	//Player information
	texture[0].loadFromFile(PLAYER_T);
	player = std::make_unique<Player>(&texture[0], sf::Vector2<unsigned>(9, 4), 0.05, PLAYER_SPEED);
	player->setPosition(sf::Vector2<float>(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));

	
	//Enemy information
	enemy = std::make_unique<Enemy>(&texture[0], sf::Vector2<unsigned>(9, 4), 0.05, PLAYER_SPEED);
	enemy->setPosition(sf::Vector2<float>(SCREEN_WIDTH / 2, SCREEN_WIDTH / 2));

}

PlayingState::~PlayingState() {
	//
}

void PlayingState::updateKeyboardInputs(sf::Keyboard::Key key, bool isPressed) {
	if (key == sf::Keyboard::Escape) { machine.run(machine.buildState<MainMenuState>(machine, window, true)); }
}

void PlayingState::updateEvents() {
	while (window.pollEvent(sfEvent)) {
		switch (sfEvent.type) {
			case sf::Event::Closed:
				machine.quit();
				break;

			case sf::Event::KeyPressed:
				updateKeyboardInputs(sfEvent.key.code, true);
				player->keyboardInputs(sfEvent.key.code, true);
				enemy->keyboardInput(sfEvent.key.code, true);
				break;

			case sf::Event::KeyReleased:
				updateKeyboardInputs(sfEvent.key.code, false);
				player->keyboardInputs(sfEvent.key.code, false);
				enemy->keyboardInput(sfEvent.key.code, false);
				break;
		}
	}
}

void PlayingState::update() {
	fpsCounter.updateCounter();

	/*------------------------------------------------------------------------------------------------------------------*/
	//Generalized Updating
	player->updateBorderBounds();
	player->updatePlayer(true);

	enemy->update(true);

	/*-------------------------------------------------------------------------------------------------------------------*/


}

void PlayingState::render() {
	window.clear();

	//Render items
	fpsCounter.renderTo(window);
	versionText.renderTo(window);

	player->renderTo(window);
	enemy->renderTo(window);

	window.display();
}