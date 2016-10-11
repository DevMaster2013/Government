#pragma once

namespace gov
{
	///
	/// Implements the Game time span that descripe the offset in date and time
	///
	class GameTimeSpan
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
		GameTimeSpan();

		///
		/// The initialization constructor
		///
		GameTimeSpan(int days, int hours, int minutes, int seconds, int milliseconds = 0);

		///
		/// The Copy Constructor
		///
		GameTimeSpan(const GameTimeSpan& src);

		///
		/// The destructor of the game time span
		///
		~GameTimeSpan();

	public:
		///
		/// Construct a game time span from number of milliseconds
		///
		static GameTimeSpan fromMilliseconds(double milliseconds);

		///
		/// Construct a game time span from number of seconds
		///
		static GameTimeSpan fromSeconds(double seconds);

		///
		/// Construct a game time span from number of minutes
		///
		static GameTimeSpan fromMinutes(double minutes);

		///
		/// Construct a game time span from number of hours
		///
		static GameTimeSpan fromHours(double hours);

		///
		/// Construct a game time span from number of days
		///
		static GameTimeSpan fromDays(double days);

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
		/// Assignment operator
		///
		GameTimeSpan& operator=(const GameTimeSpan& rhs);

		///
		/// Comparison operators
		///
		bool operator==(const GameTimeSpan& rhs);
		bool operator!=(const GameTimeSpan& rhs);
		bool operator> (const GameTimeSpan& rhs);
		bool operator< (const GameTimeSpan& rhs);
		bool operator>=(const GameTimeSpan& rhs);
		bool operator<=(const GameTimeSpan& rhs);

		///
		/// Arithmatics operators
		///
		GameTimeSpan operator+(const GameTimeSpan& rhs);
		GameTimeSpan operator-(const GameTimeSpan& rhs);
		GameTimeSpan operator*(double scale);
		GameTimeSpan operator/(double scale);
		GameTimeSpan& operator+=(const GameTimeSpan& rhs);
		GameTimeSpan& operator-=(const GameTimeSpan& rhs);
		GameTimeSpan& operator*=(double scale);
		GameTimeSpan& operator/=(double scale);
	};
}

