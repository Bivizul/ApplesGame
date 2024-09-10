#pragma once
#include "Math.h"
#include <SFML/Graphics.hpp>

namespace ApplesGame
{
	struct ScoreTableItem
	{
		sf::Text playerNick;
		sf::Text playerScore;
	};

	struct UI
	{
		sf::Text gameModeTitleText;
		sf::Text finiteApplesText;
		sf::Text infiniteApplesText;
		sf::Text accelerationOnText;
		sf::Text accelerationOffText;

		sf::Text scoreText;
		sf::Text inputHintText;
		sf::Text resultGameText;

		bool isResultGameTextVisible = false;
		bool isGameModeTextVisible = false;
	};

	struct Game;

	void InitMenuUI(UI& ui, const sf::Font& font);
	void InitScoreArray(Game& game, const sf::Font& font);
	void InitUI(UI& ui, Game& game, const sf::Font& font);
	void UpdateUI(UI& ui, const Game& game);
	void DrawUI(UI& ui, Game& game, sf::RenderWindow& window);
}