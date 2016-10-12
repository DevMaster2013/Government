#include "Game.h"

using namespace gov;

gov::Game::Game()
	: _gameClock(DateTime(1200, 6, 12, 8, 30, 40, 0), 100.0)
	, _gameActive(false)
{
}

gov::Game::~Game()
{
}

bool gov::Game::initGame()
{
	if (!onInitGame())
		return false;

	_gameActive = true;
	return true;
}

void gov::Game::runGame()
{
	DateTime currentTime = DateTime::now();	
	while (_gameActive)
	{
		TimeSpan elapsedTime = DateTime::now() - currentTime;
		currentTime = DateTime::now();
		double elapsedSeconds = elapsedTime.getTotalSeconds();

		_gameClock.updateClock(elapsedSeconds);
		onUpdateGame(elapsedSeconds);
	}
}

void gov::Game::exitGame()
{
	onExitGame();
}

bool gov::Game::onInitGame()
{
	return true;
}

void gov::Game::onUpdateGame(double elapsedTime)
{
}

void gov::Game::onExitGame()
{
}
