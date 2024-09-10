#pragma once
#include "Apple.h"
#include "Player.h"
#include "Rock.h"
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>

namespace ApplesGame
{
	struct Game;

	struct GameStatePlayingData
	{
		// Resources
		sf::Font font;

		sf::Texture playerTexture;
		sf::Texture appleTexture;
		sf::Texture rockTexture;

		sf::SoundBuffer appleEatBuffer;
		sf::SoundBuffer deathBuffer;
		sf::Sound appleEatSound;
		sf::Sound deathSound;

		// Game data
		Player player;
		std::vector<Apple> apples;
		ApplesGrid applesGrid;
		int numEatenApples = 0;
		std::vector<Rock> rocks;

		// UI data
		sf::Text scoreText;
		sf::Text inputHintText;
	};

	void InitGameStatePlaying(GameStatePlayingData& data, Game& game);
	void ShutdownGameStatePlaying(GameStatePlayingData& data, Game& game);
	void HandleGameStatePlayingWindowEvent(GameStatePlayingData& data, Game& game, const sf::Event& event);
	void UpdateGameStatePlaying(GameStatePlayingData& data, Game& game, float timeDelta);
	void SetGameOverState(GameStatePlayingData& data, Game& game);
	void DrawGameStatePlaying(GameStatePlayingData& data, Game& game, sf::RenderWindow& window);
}