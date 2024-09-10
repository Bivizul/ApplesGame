#pragma once
#include <SFML/Graphics.hpp>

namespace ApplesGame
{
	struct GameStateWinData
	{

	};

	void InitGameStateWin(GameStateWinData& data, Game& game);
	void HandleGameStateWinWindowEvent(Game& game, const sf::Event& event);
}