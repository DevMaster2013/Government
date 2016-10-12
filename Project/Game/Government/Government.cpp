
#include "..\..\GameModule\GameModule.h"
#include <iostream>

using namespace gov;

class MyGame : public Game
{
	virtual bool onInitGame() override
	{
		_gameClock.setStartTime(DateTime(2000, 10, 10, 10, 10, 10, 10));
		_gameClock.setTimeScale(60 * 60);
		return true;
	}

	virtual void onUpdateGame(double elapsedTime) override
	{
		const DateTime& currentTime = _gameClock.getCurrentTime();

		std::cout << "Current Time: ";
		std::cout << currentTime.getDay() << "\\" << currentTime.getMonth() << "\\" << currentTime.getYear() << " ";
		std::cout << currentTime.getHour() << ":" << currentTime.getMinute() << ":" << currentTime.getSecond() << ".";
		std::cout << currentTime.getMillisecond() << std::endl;

		_sleep(1000);
	}
};

int main()
{
	MyGame myGame;

	myGame.initGame();
	myGame.runGame();
	myGame.exitGame();

	return 0;
}