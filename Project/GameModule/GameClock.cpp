#include "GameClock.h"

using namespace gov;

gov::GameClock::GameClock()
	: _currentDate()
	, _timeScale(1.0)
{
}

gov::GameClock::GameClock(const DateTime & startTime, double scale)
	: _currentDate(startTime)
	, _timeScale(scale)
{
}

gov::GameClock::~GameClock()
{
}

const DateTime & gov::GameClock::getCurrentTime() const
{
	return _currentDate;
}

double gov::GameClock::getTimeScale() const
{
	return _timeScale;
}

void gov::GameClock::setStartTime(const DateTime & startTime)
{
	_currentDate = startTime;
}

void gov::GameClock::setTimeScale(double timeScale)
{
	_timeScale = timeScale;
}

void gov::GameClock::updateClock(double elapsedTime)
{
	_currentDate += TimeSpan::fromSeconds(elapsedTime) * _timeScale;
}
