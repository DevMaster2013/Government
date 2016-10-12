#define WIN32_LEAN_AND_MEAN

#include "DateTime.h"
#include <windows.h>

using namespace gov;

static const unsigned short MILLISECONDS_IN_SECOND = 1000;
static const unsigned short SECONDS_IN_MINUTE = 60;
static const unsigned short MINUTES_IN_HOUR = 60;
static const unsigned short HOURS_IN_DAY = 24;

DateTime::DateTime()
	: _year(1)
	, _month(1)
	, _day(1)
	, _hour(0)
	, _minute(0)
	, _second(0)
	, _milliseconds(0)
{
}

gov::DateTime::DateTime(unsigned short year, unsigned short month, unsigned short day, unsigned short hour, unsigned short minute, unsigned short second, unsigned short milliseconds)
	: _year(year)
	, _month(month)
	, _day(day)
	, _hour(hour)
	, _minute(minute)
	, _second(second)
	, _milliseconds(milliseconds)
{
}

gov::DateTime::DateTime(const DateTime & src)
	: _year(src._year)
	, _month(src._month)
	, _day(src._day)
	, _hour(src._hour)
	, _minute(src._minute)
	, _second(src._second)
	, _milliseconds(src._milliseconds)
{
}

DateTime::~DateTime()
{
}

DateTime gov::DateTime::now()
{
	DateTime now;

	SYSTEMTIME st;
	GetLocalTime(&st);
	
	now._year = st.wYear;
	now._month = st.wMonth;
	now._day = st.wDay;
	now._hour = st.wHour;
	now._minute = st.wMinute;
	now._second = st.wSecond;
	now._milliseconds = st.wMilliseconds;

	return now;
}

bool gov::DateTime::isLeapYear(unsigned short year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	return false;
}

unsigned short gov::DateTime::getDaysInYear(unsigned short year)
{
	unsigned short days = 0;
	for (unsigned short i = 1; i <= 12; i++)
		days += getDaysInMonth(year, i);
	return days;
}

unsigned short gov::DateTime::getDaysInMonth(unsigned short year, unsigned short month)
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		return isLeapYear(year) ? 29 : 28;
	}
	return 0;
}

unsigned short gov::DateTime::getYear() const
{
	return _year;
}

unsigned short gov::DateTime::getMonth() const
{
	return _month;
}

unsigned short gov::DateTime::getDay() const
{
	return _day;
}

unsigned short gov::DateTime::getHour() const
{
	return _hour;
}

unsigned short gov::DateTime::getMinute() const
{
	return _minute;
}

unsigned short gov::DateTime::getSecond() const
{
	return _second;
}

unsigned short gov::DateTime::getMillisecond() const
{
	return _milliseconds;
}

unsigned short gov::DateTime::getDayOfYear() const
{
	unsigned short days = 0;
	for (unsigned short month = 1; month < _month; month++)
		days += getDaysInMonth(_year, month);
	days += _day;
	return days;
}

TimeSpan gov::DateTime::getDayTime() const
{
	return TimeSpan(0, _hour, _minute, _second, _milliseconds);
}

DateTime & gov::DateTime::operator=(const DateTime & rhs)
{
	if (this == &rhs)
		return *this;
	_year = rhs._year;
	_month = rhs._month;
	_day = rhs._day;
	_hour = rhs._hour;
	_minute = rhs._minute;
	_second = rhs._second;
	_milliseconds = rhs._milliseconds;
	return *this;
}

bool gov::DateTime::operator==(const DateTime & rhs)
{
	bool equals = (_year == rhs._year) && (_month == rhs._month)
		&& (_day == rhs._day) && (_hour == rhs._day) && (_minute == rhs._minute)
		&& (_second == rhs._second) && (_milliseconds == rhs._milliseconds);
	return equals;
}

bool gov::DateTime::operator!=(const DateTime & rhs)
{
	return !(*this == rhs);
}

bool gov::DateTime::operator>(const DateTime & rhs)
{
	if (_year > rhs._year)
		return true;
	else if (_year < rhs._year)
		return false;
	
	if (_month > rhs._month)
		return true;
	else if (_month < rhs._month)
		return false;

	if (_day > rhs._day)
		return true;
	else if (_day < rhs._day)
		return false;

	if (_hour > rhs._hour)
		return true;
	else if (_hour < rhs._hour)
		return false;

	if (_minute > rhs._minute)
		return true;
	else if (_minute < rhs._minute)
		return false;

	if (_second > rhs._second)
		return true;
	else if (_second < rhs._second)
		return false;

	if (_milliseconds > rhs._milliseconds)
		return true;
	else if (_milliseconds < rhs._milliseconds)
		return false;

	return false;
}

bool gov::DateTime::operator<(const DateTime & rhs)
{
	return !(*this >= rhs);
}

bool gov::DateTime::operator>=(const DateTime & rhs)
{
	return (*this == rhs) || (*this > rhs);
}

bool gov::DateTime::operator<=(const DateTime & rhs)
{
	return (*this == rhs) || (*this < rhs);
}

DateTime gov::DateTime::operator+(const DateTime& rhs)
{
	DateTime zeroTime(0, 0, 0, 0, 0, 0, 0);
	return *this + (*(const_cast<DateTime*>(&rhs)) - zeroTime);
}

DateTime gov::DateTime::operator+(const TimeSpan & rhs)
{
	TimeSpan simplified = rhs.simplify();
	auto totalDays = simplified.getDays();

	DateTime current(*this);

	// maintain the time part
	current._milliseconds += simplified.getMilliseconds();
	if (current._milliseconds > MILLISECONDS_IN_SECOND - 1)
	{
		current._second++;
		current._milliseconds = current._milliseconds - MILLISECONDS_IN_SECOND;
	}
	current._second += simplified.getSeconds();
	if (current._second > SECONDS_IN_MINUTE - 1)
	{
		current._minute++;
		current._second = current._second - SECONDS_IN_MINUTE;
	}
	current._minute += simplified.getMinutes();
	if (current._minute > MINUTES_IN_HOUR - 1)
	{
		current._hour++;
		current._minute = current._minute - MINUTES_IN_HOUR;
	}
	current._hour += simplified.getHours();
	if (current._hour > HOURS_IN_DAY - 1)
	{
		totalDays++;
		current._hour = current._hour - HOURS_IN_DAY;
	}

	// start to the next year
	unsigned short remDays = getDaysInYear(current._year) - current.getDayOfYear();
	if (remDays <= totalDays)
	{
		current._year++;
		current._month = 1;
		current._day = 0;
		totalDays -= remDays;
	}

	// increase years
	do
	{
		unsigned short currentYearDays = getDaysInYear(current._year);
		if (currentYearDays <= totalDays)
		{
			current._year++;
			totalDays -= currentYearDays;
		}
		else
			break;
	} while (true);

	// increase months
	do
	{
		unsigned short currentMonthDays = getDaysInMonth(current._year, current._month);
		if (currentMonthDays <= totalDays)
		{
			current._month++;
			totalDays -= currentMonthDays;
		}
		else
			break;
	} while (true);

	// increase the remaining days
	current._day += totalDays;

	return current;
}

TimeSpan gov::DateTime::operator-(const DateTime & rhs)
{
	TimeSpan elapsedTime;
	if (*this < rhs)
	{
		elapsedTime = *(const_cast<DateTime*>(&rhs)) - *(const_cast<DateTime*>(this));
		return elapsedTime.reverse();
	}
	
	elapsedTime += TimeSpan::fromDays(1.0) - rhs.getDayTime();
	elapsedTime += getDayTime();

	elapsedTime += TimeSpan::fromDays(getDaysInYear(rhs._year + 1) - rhs.getDayOfYear() - 1);
	elapsedTime += TimeSpan::fromDays(getDayOfYear());

	for (unsigned short year = rhs._year + 1; year < _year; year++)
		elapsedTime += TimeSpan::fromDays(getDaysInYear(year));
	return elapsedTime;
}

DateTime & gov::DateTime::operator+=(const DateTime & rhs)
{
	return (*this = *this + rhs);
}

DateTime & gov::DateTime::operator+=(const TimeSpan & rhs)
{
	return (*this = *this + rhs);
}
