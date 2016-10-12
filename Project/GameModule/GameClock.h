#pragma once

#include "DateTime.h"
#include "TimeSpan.h"

namespace gov
{
	///
	/// This class is resoinsible for managing the current game time
	/// which will be scaled with a specified scaler to simulate the 
	/// world time in game world
	class GameClock
	{
	private:
		DateTime _currentDate;		/// The current date in the game clock
		double _timeScale;			/// The amount of scaling time in the clock

	public:
		///
		/// The default constructor
		///
		GameClock();

		///
		/// The initialization constructor
		///
		GameClock(const DateTime& startTime, double scale);

		///
		/// The destructor
		///
		~GameClock();

	public:
		///
		/// Get the current time represented by the game clock
		///
		const DateTime& getCurrentTime() const;

		///
		/// Get the time scale
		///
		double getTimeScale() const;

	public:
		///
		/// Set the start date of the clock
		///
		void setStartTime(const DateTime& startTime);

		///
		/// Set the time scale
		///
		void setTimeScale(double timeScale);

	public:
		///
		/// Update the game clock from a real elapsed time
		///
		void updateClock(double elapsedTime);
	};
}

