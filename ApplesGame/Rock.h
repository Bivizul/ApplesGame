#pragma once
#include "Math.h"
#include <SFML/Graphics.hpp>

namespace ApplesGame
{
	struct Rock
	{
		Position position;
		sf::Sprite sprite;
	};

	void InitRocks(Rock& rock, const sf::Texture& texture);
	void DrawRock(Rock& rock, sf::RenderWindow& window);
	bool FindPlayerCollisionWithRock(const Vector2D& playerPosition, const Vector2D& rockPosition);
}