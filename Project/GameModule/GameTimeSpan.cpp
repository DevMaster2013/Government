#include "GameTimeSpan.h"
#include <cmath>
#include <limits>

static const double MILLISECONDS_IN_SECOND = 1000.0;
static const double SECONDS_IN_MINUTE = 60.0;
static const double MINUTES_IN_HOUR = 60.0;
static const double HOURS_IN_DAY = 24.0;
static const double MILLISECONDS_IN_MINUTE = SECONDS_IN_MINUTE * MILLISECONDS_IN_SECOND;
static const double MILLISECONDS_IN_HOUR = MINUTES_IN_HOUR * MILLISECONDS_IN_MINUTE;
static const double MILLISECONDS_IN_DAY = HOURS_IN_DAY * MILLISECONDS_IN_HOUR;
static const double SECONDS_IN_HOUR = MINUTES_IN_HOUR * SECONDS_IN_MINUTE;
static const double SECONDS_IN_DAY = HOURS_IN_DAY * SECONDS_IN_HOUR;
static const double MINUTES_IN_DAY = MINUTES_IN_HOUR * HOURS_IN_DAY;

gov::GameTimeSpan::GameTimeSpan()
	: _days(0)
	, _hours(0)
	, _minutes(0)
	, _seconds(0)
	, _milliseconds(0)
{
}

gov::GameTimeSpan::GameTimeSpan(int days, int hours, int minutes, int seconds, int milliseconds)
	: _days(days)
	, _hours(hours)
	, _minutes(minutes)
	, _seconds(seconds)
	, _milliseconds(milliseconds)
{
}

gov::GameTimeSpan::GameTimeSpan(const GameTimeSpan& src)
	: _days(src._days)
	, _hours(src._hours)
	, _minutes(src._minutes)
	, _seconds(src._seconds)
	, _milliseconds(src._milliseconds)
{
}

gov::GameTimeSpan::~GameTimeSpan()
{
}

gov::GameTimeSpan gov::GameTimeSpan::fromMilliseconds(double milliseconds)
{
	GameTimeSpan timeSpan;

	double seconds = milliseconds / MILLISECONDS_IN_SECOND;
	double minutes = seconds / SECONDS_IN_MINUTE;
	double hours = minutes / MINUTES_IN_HOUR;
	double days = hours / HOURS_IN_DAY;

	timeSpan._days = static_cast<int>(std::floor(days));
	hours = (days - timeSpan._days) * HOURS_IN_DAY;
	timeSpan._hours = static_cast<int>(std::floor(hours));
	minutes = (hours - timeSpan._hours) * MINUTES_IN_HOUR;
	timeSpan._minutes = static_cast<int>(std::floor(minutes));
	seconds = (minutes - timeSpan._minutes) * SECONDS_IN_MINUTE;
	timeSpan._seconds = static_cast<int>(std::floor(seconds));
	timeSpan._milliseconds = static_cast<int>(std::round((seconds - timeSpan._seconds) * MILLISECONDS_IN_SECOND));

	return timeSpan;
}

gov::GameTimeSpan gov::GameTimeSpan::fromSeconds(double seconds)
{
	return fromMilliseconds(seconds * MILLISECONDS_IN_SECOND);
}

gov::GameTimeSpan gov::GameTimeSpan::fromMinutes(double minutes)
{
	return fromSeconds(minutes * SECONDS_IN_MINUTE);
}

gov::GameTimeSpan gov::GameTimeSpan::fromHours(double hours)
{
	return fromMinutes(hours * MINUTES_IN_HOUR);
}

gov::GameTimeSpan gov::GameTimeSpan::fromDays(double days)
{
	return fromHours(days * HOURS_IN_DAY);
}

int gov::GameTimeSpan::getDays() const
{
	return _days;
}

int gov::GameTimeSpan::getHours() const
{
	return _hours;
}

int gov::GameTimeSpan::getMinutes() const
{
	return _minutes;
}

int gov::GameTimeSpan::getSeconds() const
{
	return _seconds;
}

int gov::GameTimeSpan::getMilliseconds() const
{
	return _milliseconds;
}

double gov::GameTimeSpan::getTotalDays() const
{
	double days = 
		_days +
		_hours / HOURS_IN_DAY +
		_minutes / MINUTES_IN_DAY +
		_seconds / SECONDS_IN_DAY +
		_milliseconds / MILLISECONDS_IN_DAY;
	return days;
}

double gov::GameTimeSpan::getTotalHours() const
{
	double hours =
		_days * HOURS_IN_DAY +
		_hours +
		_minutes / MINUTES_IN_HOUR +
		_seconds / SECONDS_IN_HOUR +
		_milliseconds / MILLISECONDS_IN_HOUR;
	return hours;
}

double gov::GameTimeSpan::getTotalMinutes() const
{
	double minutes =
		_days * MINUTES_IN_DAY +
		_hours * MINUTES_IN_HOUR +
		_minutes +
		_seconds / SECONDS_IN_MINUTE +
		_milliseconds / MILLISECONDS_IN_MINUTE;
	return minutes;
}

double gov::GameTimeSpan::getTotalSeconds() const
{
	double seconds =
		_days * SECONDS_IN_DAY +
		_hours * SECONDS_IN_HOUR +
		_minutes * SECONDS_IN_MINUTE +
		_seconds +
		_milliseconds / MILLISECONDS_IN_SECOND;
	return seconds;
}

double gov::GameTimeSpan::getTotalMilliseconds() const
{
	double milliseconds =
		_days * MILLISECONDS_IN_DAY +
		_hours * MILLISECONDS_IN_HOUR +
		_minutes * MILLISECONDS_IN_MINUTE +
		_seconds * MILLISECONDS_IN_SECOND +
		_milliseconds;
	return milliseconds;
}

gov::GameTimeSpan& gov::GameTimeSpan::operator=(const GameTimeSpan & rhs)
{
	if (this == &rhs)
		return *this;

	_days = rhs._days;
	_hours = rhs._hours;
	_minutes = rhs._minutes;
	_seconds = rhs._seconds;
	_milliseconds = rhs._milliseconds;

	return *this;
}

bool gov::GameTimeSpan::operator==(const GameTimeSpan & rhs)
{
	return std::abs(getTotalMilliseconds() - rhs.getTotalMilliseconds()) < DBL_EPSILON;
}

bool gov::GameTimeSpan::operator!=(const GameTimeSpan & rhs)
{
	return !(*this == rhs);
}

bool gov::GameTimeSpan::operator>(const GameTimeSpan & rhs)
{
	return getTotalMilliseconds() > rhs.getTotalMilliseconds();
}

bool gov::GameTimeSpan::operator<(const GameTimeSpan & rhs)
{
	return getTotalMilliseconds() < rhs.getTotalMilliseconds();
}

bool gov::GameTimeSpan::operator>=(const GameTimeSpan & rhs)
{
	return getTotalMilliseconds() >= rhs.getTotalMilliseconds();
}

bool gov::GameTimeSpan::operator<=(const GameTimeSpan & rhs)
{
	return getTotalMilliseconds() <= rhs.getTotalMilliseconds();
}

gov::GameTimeSpan gov::GameTimeSpan::operator+(const GameTimeSpan & rhs)
{
	return fromMilliseconds(getTotalMilliseconds() + rhs.getTotalMilliseconds());
}

gov::GameTimeSpan gov::GameTimeSpan::operator-(const GameTimeSpan & rhs)
{
	return fromMilliseconds(getTotalMilliseconds() - rhs.getTotalMilliseconds());
}

gov::GameTimeSpan gov::GameTimeSpan::operator*(double scale)
{
	return fromMilliseconds(getTotalMilliseconds() * scale);
}

gov::GameTimeSpan gov::GameTimeSpan::operator/(double scale)
{
	return fromMilliseconds(getTotalMilliseconds() / scale);
}

gov::GameTimeSpan& gov::GameTimeSpan::operator+=(const GameTimeSpan & rhs)
{
	return (*this = *this + rhs);
}

gov::GameTimeSpan& gov::GameTimeSpan::operator-=(const GameTimeSpan & rhs)
{
	return (*this = *this - rhs);
}

gov::GameTimeSpan& gov::GameTimeSpan::operator*=(double scale)
{
	return (*this = *this * scale);
}

gov::GameTimeSpan& gov::GameTimeSpan::operator/=(double scale)
{
	return (*this = *this / scale);
}
