#include "TimeSpan.h"
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

gov::TimeSpan::TimeSpan()
	: _days(0)
	, _hours(0)
	, _minutes(0)
	, _seconds(0)
	, _milliseconds(0)
{
}

gov::TimeSpan::TimeSpan(int days, int hours, int minutes, int seconds, int milliseconds)
	: _days(days)
	, _hours(hours)
	, _minutes(minutes)
	, _seconds(seconds)
	, _milliseconds(milliseconds)
{
}

gov::TimeSpan::TimeSpan(const TimeSpan& src)
	: _days(src._days)
	, _hours(src._hours)
	, _minutes(src._minutes)
	, _seconds(src._seconds)
	, _milliseconds(src._milliseconds)
{
}

gov::TimeSpan::~TimeSpan()
{
}

gov::TimeSpan gov::TimeSpan::fromMilliseconds(double milliseconds)
{
	TimeSpan timeSpan;

	double seconds = milliseconds / MILLISECONDS_IN_SECOND;
	double minutes = seconds / SECONDS_IN_MINUTE;
	double hours = minutes / MINUTES_IN_HOUR;
	double days = hours / HOURS_IN_DAY;

	timeSpan._days = static_cast<int>(std::floor(days + 0.01));
	hours = (days - timeSpan._days) * HOURS_IN_DAY;
	timeSpan._hours = static_cast<int>(std::floor(hours + 0.01));
	minutes = (hours - timeSpan._hours) * MINUTES_IN_HOUR;
	timeSpan._minutes = static_cast<int>(std::floor(minutes + 0.01));
	seconds = (minutes - timeSpan._minutes) * SECONDS_IN_MINUTE;
	timeSpan._seconds = static_cast<int>(std::floor(seconds + 0.01));
	timeSpan._milliseconds = static_cast<int>(std::round((seconds - timeSpan._seconds) * MILLISECONDS_IN_SECOND));

	return timeSpan;
}

gov::TimeSpan gov::TimeSpan::fromSeconds(double seconds)
{
	return fromMilliseconds(seconds * MILLISECONDS_IN_SECOND);
}

gov::TimeSpan gov::TimeSpan::fromMinutes(double minutes)
{
	return fromSeconds(minutes * SECONDS_IN_MINUTE);
}

gov::TimeSpan gov::TimeSpan::fromHours(double hours)
{
	return fromMinutes(hours * MINUTES_IN_HOUR);
}

gov::TimeSpan gov::TimeSpan::fromDays(double days)
{
	return fromHours(days * HOURS_IN_DAY);
}

int gov::TimeSpan::getDays() const
{
	return _days;
}

int gov::TimeSpan::getHours() const
{
	return _hours;
}

int gov::TimeSpan::getMinutes() const
{
	return _minutes;
}

int gov::TimeSpan::getSeconds() const
{
	return _seconds;
}

int gov::TimeSpan::getMilliseconds() const
{
	return _milliseconds;
}

double gov::TimeSpan::getTotalDays() const
{
	double days = 
		_days +
		_hours / HOURS_IN_DAY +
		_minutes / MINUTES_IN_DAY +
		_seconds / SECONDS_IN_DAY +
		_milliseconds / MILLISECONDS_IN_DAY;
	return days;
}

double gov::TimeSpan::getTotalHours() const
{
	double hours =
		_days * HOURS_IN_DAY +
		_hours +
		_minutes / MINUTES_IN_HOUR +
		_seconds / SECONDS_IN_HOUR +
		_milliseconds / MILLISECONDS_IN_HOUR;
	return hours;
}

double gov::TimeSpan::getTotalMinutes() const
{
	double minutes =
		_days * MINUTES_IN_DAY +
		_hours * MINUTES_IN_HOUR +
		_minutes +
		_seconds / SECONDS_IN_MINUTE +
		_milliseconds / MILLISECONDS_IN_MINUTE;
	return minutes;
}

double gov::TimeSpan::getTotalSeconds() const
{
	double seconds =
		_days * SECONDS_IN_DAY +
		_hours * SECONDS_IN_HOUR +
		_minutes * SECONDS_IN_MINUTE +
		_seconds +
		_milliseconds / MILLISECONDS_IN_SECOND;
	return seconds;
}

double gov::TimeSpan::getTotalMilliseconds() const
{
	double milliseconds =
		_days * MILLISECONDS_IN_DAY +
		_hours * MILLISECONDS_IN_HOUR +
		_minutes * MILLISECONDS_IN_MINUTE +
		_seconds * MILLISECONDS_IN_SECOND +
		_milliseconds;
	return milliseconds;
}

gov::TimeSpan gov::TimeSpan::simplify() const
{
	return TimeSpan::fromMilliseconds(getTotalMilliseconds());
}

gov::TimeSpan gov::TimeSpan::reverse() const
{
	return TimeSpan(-_days, -_hours, -_minutes, -_seconds, -_milliseconds);
}

gov::TimeSpan& gov::TimeSpan::operator=(const TimeSpan & rhs)
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

bool gov::TimeSpan::operator==(const TimeSpan & rhs)
{
	return std::abs(getTotalMilliseconds() - rhs.getTotalMilliseconds()) < DBL_EPSILON;
}

bool gov::TimeSpan::operator!=(const TimeSpan & rhs)
{
	return !(*this == rhs);
}

bool gov::TimeSpan::operator>(const TimeSpan & rhs)
{
	return getTotalMilliseconds() > rhs.getTotalMilliseconds();
}

bool gov::TimeSpan::operator<(const TimeSpan & rhs)
{
	return getTotalMilliseconds() < rhs.getTotalMilliseconds();
}

bool gov::TimeSpan::operator>=(const TimeSpan & rhs)
{
	return getTotalMilliseconds() >= rhs.getTotalMilliseconds();
}

bool gov::TimeSpan::operator<=(const TimeSpan & rhs)
{
	return getTotalMilliseconds() <= rhs.getTotalMilliseconds();
}

gov::TimeSpan gov::TimeSpan::operator+(const TimeSpan & rhs)
{
	return fromMilliseconds(getTotalMilliseconds() + rhs.getTotalMilliseconds());
}

gov::TimeSpan gov::TimeSpan::operator-(const TimeSpan & rhs)
{
	return fromMilliseconds(getTotalMilliseconds() - rhs.getTotalMilliseconds());
}

gov::TimeSpan gov::TimeSpan::operator*(double scale)
{
	return fromMilliseconds(getTotalMilliseconds() * scale);
}

gov::TimeSpan gov::TimeSpan::operator/(double scale)
{
	return fromMilliseconds(getTotalMilliseconds() / scale);
}

gov::TimeSpan& gov::TimeSpan::operator+=(const TimeSpan & rhs)
{
	return (*this = *this + rhs);
}

gov::TimeSpan& gov::TimeSpan::operator-=(const TimeSpan & rhs)
{
	return (*this = *this - rhs);
}

gov::TimeSpan& gov::TimeSpan::operator*=(double scale)
{
	return (*this = *this * scale);
}

gov::TimeSpan& gov::TimeSpan::operator/=(double scale)
{
	return (*this = *this / scale);
}
