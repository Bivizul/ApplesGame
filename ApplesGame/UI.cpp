#include "Game.h"
#include "UI.h"

namespace ApplesGame
{
	void InitMenuUI(UI& ui, const sf::Font& font)
	{
		ui.isGameModeTextVisible = true;

		ui.gameModeTitleText.setFont(font);
		ui.gameModeTitleText.setCharacterSize(20);
		ui.gameModeTitleText.setFillColor(sf::Color::White);
		ui.gameModeTitleText.setString("Select difficulty level and press ENTER");
		SetTextOrigin(ui.gameModeTitleText, 1.f, 0.5f);

		ui.finiteApplesText.setFont(font);
		ui.finiteApplesText.setCharacterSize(20);
		ui.finiteApplesText.setFillColor(sf::Color::White);
		ui.finiteApplesText.setString("1 - with a finite number of apples");
		SetTextOrigin(ui.finiteApplesText, 1.f, 0.5f);

		ui.infiniteApplesText.setFont(font);
		ui.infiniteApplesText.setCharacterSize(20);
		ui.infiniteApplesText.setFillColor(sf::Color::White);
		ui.infiniteApplesText.setString("2 - with an infinite number of apples");
		SetTextOrigin(ui.infiniteApplesText, 1.f, 0.5f);

		ui.accelerationOnText.setFont(font);
		ui.accelerationOnText.setCharacterSize(20);
		ui.accelerationOnText.setFillColor(sf::Color::White);
		ui.accelerationOnText.setString("3 - with acceleration after eating an apple");
		SetTextOrigin(ui.accelerationOnText, 1.f, 0.5f);

		ui.accelerationOffText.setFont(font);
		ui.accelerationOffText.setCharacterSize(20);
		ui.accelerationOffText.setFillColor(sf::Color::White);
		ui.accelerationOffText.setString("4 - without acceleration");
		SetTextOrigin(ui.accelerationOffText, 1.f, 0.5f);
	}

	void InitScoreArray(Game& game, const sf::Font& font)
	{
		for (size_t i = 0; i < game.scoreFromTableArray.size(); i++)
		{
			game.scoreFromTableArray[i].setFont(font);
			game.scoreFromTableArray[i].setCharacterSize(14);
			game.scoreFromTableArray[i].setFillColor(sf::Color::White);
			SetTextOrigin(game.scoreFromTableArray[i], 0.f, 0.5f);
		}
	}

	void InitUI(UI& ui, Game& game, const sf::Font& font)
	{

		ui.scoreText.setFont(font);
		ui.scoreText.setCharacterSize(22);
		ui.scoreText.setFillColor(sf::Color::Cyan);

		ui.inputHintText.setFont(font);
		ui.inputHintText.setCharacterSize(22);
		ui.inputHintText.setFillColor(sf::Color::White);
		ui.inputHintText.setString("Use arrow keys to move, Space to restart, ESC to exit");
		SetTextOrigin(ui.inputHintText, 1.f, 0.f);

		ui.isResultGameTextVisible = false;
		ui.resultGameText.setFont(font);
		ui.resultGameText.setCharacterSize(64);
		ui.resultGameText.setStyle(sf::Text::Bold);
		ui.resultGameText.setFillColor(sf::Color::Red);

		InitMenuUI(ui, font);
		InitScoreArray(game, font);
	}

	void UpdateUI(UI& ui, const Game& game)
	{
		if (game.gameStateType == GameStateType::MAIN_MENU)
		{
			ui.isGameModeTextVisible = true;

			if (IsGameMode(game.mode, GameOptions::FINITE_APPLES))
			{
				ui.finiteApplesText.setFillColor(sf::Color::Cyan);
			}
			else
			{
				ui.finiteApplesText.setFillColor(sf::Color::White);
			}

			if (IsGameMode(game.mode, GameOptions::INFINITE_APPLES))
			{
				ui.infiniteApplesText.setFillColor(sf::Color::Cyan);
			}
			else
			{
				ui.infiniteApplesText.setFillColor(sf::Color::White);
			}
			if (IsGameMode(game.mode, GameOptions::ACCELERATION_ON))
			{
				ui.accelerationOnText.setFillColor(sf::Color::Cyan);
			}
			else
			{
				ui.accelerationOnText.setFillColor(sf::Color::White);
			}
			if (IsGameMode(game.mode, GameOptions::ACCELERATION_OFF))
			{
				ui.accelerationOffText.setFillColor(sf::Color::Cyan);
			}
			else
			{
				ui.accelerationOffText.setFillColor(sf::Color::White);
			}
		}
		else
		{
			ui.isGameModeTextVisible = false;
		}

		if (game.gameStateType == GameStateType::GAME_OVER)
		{
			ui.resultGameText.setString("GAME OVER");
			SetTextOrigin(ui.resultGameText, 0.5f, 0.5f);
		}

		if (game.gameStateType == GameStateType::WIN)
		{
			ui.resultGameText.setString("YOU WIN");
			SetTextOrigin(ui.resultGameText, 0.5f, 0.5f);
		}

		/*ui.scoreText.setString("Apples eaten: " + std::to_string(game.numEatenApples));
		ui.isResultGameTextVisible = game.isGameResult;

		for (size_t i = 0; i < ui.scoreArray.size(); ++i)
		{
			if (ui.scoreArray[i].getString().find("Player") != std::string::npos)
			{
				ui.scoreArray[i].setString("\t" + RightAlignString(std::to_string(game.maxNumEatenApples), 4) + "\t | \t" + "Player" + "\t");
			}
		}

		std::sort(ui.scoreArray.begin(), ui.scoreArray.end(), CompareByScore);*/
		ui.scoreText.setString("Apples eaten: " + std::to_string(game.numEatenApples));
		ui.isResultGameTextVisible = game.isGameResult;
	}


	void DrawUI(UI& ui, Game& game, sf::RenderWindow& window)
	{
		if (ui.isGameModeTextVisible)
		{
			ui.gameModeTitleText.setPosition((float)window.getSize().x, window.getSize().y / 3.2f);
			window.draw(ui.gameModeTitleText);

			float gameModeTitleTextHeight = ui.gameModeTitleText.getGlobalBounds().height;

			ui.finiteApplesText.setPosition((float)window.getSize().x, window.getSize().y / 3.2f + gameModeTitleTextHeight + 20);
			window.draw(ui.finiteApplesText);

			float finiteApplesTextHeight = ui.finiteApplesText.getGlobalBounds().height;

			ui.infiniteApplesText.setPosition((float)window.getSize().x, window.getSize().y / 3.2f + gameModeTitleTextHeight + 20 + finiteApplesTextHeight + 10);
			window.draw(ui.infiniteApplesText);

			float infiniteApplesTextHeight = ui.infiniteApplesText.getGlobalBounds().height;

			ui.accelerationOnText.setPosition((float)window.getSize().x, window.getSize().y / 3.2f + gameModeTitleTextHeight + 20 + finiteApplesTextHeight + 10 + infiniteApplesTextHeight + 10);
			window.draw(ui.accelerationOnText);

			float accelerationOnTextHeight = ui.accelerationOnText.getGlobalBounds().height;

			ui.accelerationOffText.setPosition((float)window.getSize().x, window.getSize().y / 3.2f + gameModeTitleTextHeight + 20 + finiteApplesTextHeight + 10 + infiniteApplesTextHeight + 10 + accelerationOnTextHeight + 10);
			window.draw(ui.accelerationOffText);

			/*for (size_t i = 0; i < ui.scoreArray.size(); ++i) {
				ui.scoreArray[i].setPosition(0.f, window.getSize().y / 3.f + i * 30.f);
				window.draw(ui.scoreArray[i]);
			}*/
			for (size_t i = 0; i < game.scoreFromTableArray.size(); ++i)
			{
				game.scoreFromTableArray[i].setPosition(0.f, window.getSize().y / 3.f + i * 30.f);
				window.draw(game.scoreFromTableArray[i]);
			}
		}

		ui.scoreText.setPosition(10.f, 10.f);
		window.draw(ui.scoreText);

		ui.inputHintText.setPosition(window.getSize().x - 10.f, 10.f);
		window.draw(ui.inputHintText);

		if (ui.isResultGameTextVisible)
		{
			ui.resultGameText.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
			window.draw(ui.resultGameText);
		}
	}
}
