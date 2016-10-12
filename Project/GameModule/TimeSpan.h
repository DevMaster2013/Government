#pragma once

namespace gov
{
	///
	/// Implements the Game time span that descripe the offset in date and time
	///
	class TimeSpan
	{
	private:
		int _days;			/// This descripe the number of days
		int _hours;			/// This descripe the number of hours
		int _minutes;		/// This descripe the number of minutes
		int _seconds;		/// This descripe the number of seconds
		int _milliseconds;	/// This descripe the number of milliseconds

	public:
		///
		/// The Default constructor
		///
		TimeSpan();

		///
		/// The initialization constructor
		///
		TimeSpan(int days, int hours, int minutes, int seconds, int milliseconds = 0);

		///
		/// The Copy Constructor
		///
		TimeSpan(const TimeSpan& src);

		///
		/// The destructor of the game time span
		///
		~TimeSpan();

	public:
		///
		/// Construct a game time span from number of milliseconds
		///
		static TimeSpan fromMilliseconds(double milliseconds);

		///
		/// Construct a game time span from number of seconds
		///
		static TimeSpan fromSeconds(double seconds);

		///
		/// Construct a game time span from number of minutes
		///
		static TimeSpan fromMinutes(double minutes);

		///
		/// Construct a game time span from number of hours
		///
		static TimeSpan fromHours(double hours);

		///
		/// Construct a game time span from number of days
		///
		static TimeSpan fromDays(double days);

	public:
		///
		/// Return the the number of days
		///
		int getDays() const;

		///
		/// Return the the number of hours
		///
		int getHours() const;

		///
		/// Return the the number of minutes
		///
		int getMinutes() const;

		///
		/// Return the the number of seconds
		///
		int getSeconds() const;

		///
		/// Return the the number of milliseconds
		///
		int getMilliseconds() const;

		///
		/// Return the the total number of days
		///
		double getTotalDays() const;

		///
		/// Return the the total number of hours
		///
		double getTotalHours() const;

		///
		/// Return the the total number of minutes
		///
		double getTotalMinutes() const;

		///
		/// Return the the total number of seconds
		///
		double getTotalSeconds() const;

		///
		/// Return the the total number of milliseconds
		///
		double getTotalMilliseconds() const;

	public:
		///
		/// Simplify the timespan by letting each component sums to the larger component
		///
		TimeSpan simplify() const;

		///
		/// Reverse the time span to be negative
		///
		TimeSpan reverse() const;

	public:
		///
		/// Assignment operator
		///
		TimeSpan& operator=(const TimeSpan& rhs);

		///
		/// Comparison operators
		///
		bool operator==(const TimeSpan& rhs);
		bool operator!=(const TimeSpan& rhs);
		bool operator> (const TimeSpan& rhs);
		bool operator< (const TimeSpan& rhs);
		bool operator>=(const TimeSpan& rhs);
		bool operator<=(const TimeSpan& rhs);

		///
		/// Arithmatics operators
		///
		TimeSpan operator+(const TimeSpan& rhs);
		TimeSpan operator-(const TimeSpan& rhs);
		TimeSpan operator*(double scale);
		TimeSpan operator/(double scale);
		TimeSpan& operator+=(const TimeSpan& rhs);
		TimeSpan& operator-=(const TimeSpan& rhs);
		TimeSpan& operator*=(double scale);
		TimeSpan& operator/=(double scale);
	};
}

