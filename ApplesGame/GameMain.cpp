#include "Game.h"
#include <SFML/Graphics.hpp>
#include <windows.h>

using namespace ApplesGame;

static void AttachConsole()
{
	if (AllocConsole())
	{
		FILE* newStdout;
		FILE* newStderr;
		FILE* newStdin;

		// Redirect stdout to console
		freopen_s(&newStdout, "CONOUT$", "w", stdout);
		// Redirect stderr to console
		freopen_s(&newStderr, "CONOUT$", "w", stderr);
		// Redirect stdin to console
		freopen_s(&newStdin, "CONIN$", "r", stdin);
	}
}

int main()
{
	AttachConsole(); // Open console with game window

	// Init random number generator
	unsigned int seed = (unsigned int)time(nullptr); // Get current time as seed. You can also use any other number to fix randomization
	srand(seed);

	// Init window
	sf::RenderWindow window(sf::VideoMode(ApplesGame::SCREEN_WIDTH, ApplesGame::SCREEN_HEIGHT), "AppleGame");

	// We now use too much memory for stack, so we need to allocate it on heap
	ApplesGame::Game* game = new ApplesGame::Game();
	InitGame(*game);

	// Init game clock
	sf::Clock game_clock;
	sf::Time lastTime = game_clock.getElapsedTime();

	// Game loop
	while (window.isOpen())
	{
		HandleWindowEvents(*game, window);

		if (!window.isOpen())
		{
			break;
		}

		// Calculate time delta
		sf::Time currentTime = game_clock.getElapsedTime();
		float timeDelta = currentTime.asSeconds() - lastTime.asSeconds();
		lastTime = currentTime;
		if (UpdateGame(*game, timeDelta))
		{
			// Draw everything here
		// Clear the window first
			window.clear();

			DrawGame(*game, window);

			// End the current frame, display window contents on screen
			window.display();
		}
		else
		{
			window.close();
		}
	}

	ShutdownGame(*game);
	delete game;
	game = nullptr;

	return 0;
}