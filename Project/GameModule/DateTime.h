#pragma once

#include "TimeSpan.h"

namespace gov
{
	///
	/// The class that represent a date and time in the game
	///
	class DateTime
	{
	private:
		unsigned short _year;			/// The year of the date time
		unsigned short _month;			/// The year of the date time
		unsigned short _day;			/// The year of the date time
		unsigned short _hour;			/// The year of the date time
		unsigned short _minute;			/// The year of the date time
		unsigned short _second;			/// The year of the date time
		unsigned short _milliseconds;	/// The year of the date time

	public:
		///
		/// The Default constructor
		///
		DateTime();

		///
		/// The initialization constructor
		///
		DateTime(unsigned short year, unsigned short month, unsigned short day, unsigned short hour, unsigned short minute, unsigned short second, unsigned short milliseconds);

		///
		/// The copy constructor
		///
		DateTime(const DateTime& src);

		///
		/// The destructor
		///
		~DateTime();

	public:
		///
		/// Return the current date time in the system
		///
		static DateTime now();

		///
		/// Check is a specific year is leap year or not
		///
		static bool isLeapYear(unsigned short year);

		///
		/// Get the number of days in a specific year
		///
		static unsigned short getDaysInYear(unsigned short year);

		///
		/// Get the number of days in a specific month is a specific year
		///
		static unsigned short getDaysInMonth(unsigned short year, unsigned short month);

	public:
		///
		/// Return the year component of the date time object
		///
		unsigned short getYear() const;

		///
		/// Return the month component of the date time object
		///
		unsigned short getMonth() const;

		///
		/// Return the day component of the date time object
		///
		unsigned short getDay() const;

		///
		/// Return the hour component of the date time object
		///
		unsigned short getHour() const;

		///
		/// Return the minute component of the date time object
		///
		unsigned short getMinute() const;

		///
		/// Return the second component of the date time object
		///
		unsigned short getSecond() const;

		///
		/// Return the millisecond component of the date time object
		///
		unsigned short getMillisecond() const;

		///
		/// Return the number of the days passed in the current year
		///
		unsigned short getDayOfYear() const;

		///
		/// Get the current day time
		///
		TimeSpan getDayTime() const;

	public:
		///
		/// The Assignment opeartor
		///
		DateTime& operator=(const DateTime& rhs);

		///
		/// The comparison operators
		///
		bool operator==(const DateTime& rhs);
		bool operator!=(const DateTime& rhs);
		bool operator> (const DateTime& rhs);
		bool operator< (const DateTime& rhs);
		bool operator>=(const DateTime& rhs);
		bool operator<=(const DateTime& rhs);

		///
		/// The arithmetic operators
		///
		DateTime operator+(const DateTime& rhs);
		DateTime operator+(const TimeSpan& rhs);
		TimeSpan operator-(const DateTime& rhs);
		DateTime& operator+=(const DateTime& rhs);
		DateTime& operator+=(const TimeSpan& rhs);
	};

	///
	/// Statis Arithmetic operators
	///
	static DateTime operator+(const TimeSpan& lhs, const DateTime& rhs)
	{
		return *(const_cast<DateTime*>(&rhs)) + lhs;
	}
}

