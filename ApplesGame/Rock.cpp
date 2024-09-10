#include "GameSettings.h"
#include "Math.h"
#include "Rock.h"

namespace ApplesGame
{
	void InitRocks(Rock& rock, const sf::Texture& texture)
	{
		rock.sprite.setTexture(texture);
		rock.sprite.setOrigin(GetItemOrigin(rock.sprite, { 0.5f, 0.5f })); // We need to use texture as origin ignores scale
		rock.sprite.setScale(GetSpriteScale(rock.sprite, { ROCK_SIZE, ROCK_SIZE }));
		rock.position = GetRandomPositionInScreen(SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	void DrawRock(Rock& rock, sf::RenderWindow& window)
	{
		rock.sprite.setPosition(OurVectorToSf(rock.position));
		window.draw(rock.sprite);
	}

	bool FindPlayerCollisionWithRock(const Vector2D& playerPosition, const Vector2D& rockPosition)
	{
		float deltaX = (float)fabs(playerPosition.x - rockPosition.x);
		float deltaY = (float)fabs(playerPosition.y - rockPosition.y);
		return (deltaX <= (PLAYER_SIZE + ROCK_SIZE) / 2.f && deltaY <= (PLAYER_SIZE + ROCK_SIZE) / 2.f);
	}
}