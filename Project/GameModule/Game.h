#pragma once

#include "GameClock.h"

namespace gov
{
	///
	/// The Main game class that is the main entry to the applicaton
	///
	class Game
	{
	protected:
		GameClock _gameClock;		/// The game clock
		bool _gameActive;			/// Is the game active or not

	public:
		///
		/// The default constructor
		///
		Game();

		///
		/// The destructor
		///
		virtual ~Game();

	public:
		///
		/// Initialize the game resources
		///
		bool initGame();

		///
		/// Run the game continusily
		///
		void runGame();

		///
		/// Exit the game
		///
		void exitGame();

	protected:
		///
		/// Implemented on derived classes to tweak initialization
		///
		virtual bool onInitGame();

		///
		/// Implemented on derived classes to update the game
		///
		virtual void onUpdateGame(double elapsedTime);		

		///
		/// Implemented on derived classes to tweak finalization of game
		///
		virtual void onExitGame();

	private:
		///
		/// Initialize game logging mechanism
		///
		void initializeLogging();
	};
}

