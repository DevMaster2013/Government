#include "Game.h"
#include "LogManager.h"
#include "BaseGameLog.h"
#include "ConsoleLog.h"

using namespace gov;

#define LOGMNG LogManager::getInstance()

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
	initializeLogging();	

	if (!onInitGame())
	{
		LOGMNG->log("Game initialized failed");
		return false;
	}

	_gameActive = true;

	LOGMNG->log("Game initialized success");

	return true;
}

void gov::Game::runGame()
{
	LOGMNG->log("Game started");

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

	LOGMNG->log("Game exited");
	LogManager::finalizeLogManager();
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

void gov::Game::initializeLogging()
{
	LOGMNG->initialize();
	LOGMNG->addLog("BaseLog", new BaseGameLog("GameLog.txt"));
	LOGMNG->addLog("ConsoleLog", new ConsoleLog());

	LOGMNG->log("Logging manager created");
}
