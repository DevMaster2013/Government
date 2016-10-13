#pragma once

#include <map>
#include "BaseGameObject.h"
#include "IGameLog.h"

namespace gov
{
	///
	/// The Game Logging manager that manage logging messages in the game
	///
	class LogManager : public BaseGameObject
	{
	private:
		std::map<std::string, IGameLog*> _loggers;	/// The list of all loggers in the game

	private:
		static LogManager* _singleInstance;				/// The singlton instance of the logging manager

	private:
		///
		/// The default contructor
		///
		LogManager();

	public:
		///
		/// The destructor
		///
		~LogManager();

	public:
		///
		/// The singlton interface method for handling game manager
		///
		static LogManager* getInstance();

		///
		/// Finalize the log manager
		///
		static void finalizeLogManager();

	public:
		///
		/// Add a new log mechanism to the logging manager
		///
		void addLog(const std::string& logName, IGameLog* gameLog);

		/// 
		/// Get a log from logging manager
		///
		IGameLog* getLog(const std::string& logName);

		///
		/// Removes the log from the logging manager
		///
		void removeLog(const std::string& logName);

	public:
		///
		/// Log the message into the logging stream
		///
		void log(const std::string& message);

	public:
		///
		/// Inherited from BaseGameObject
		///
		virtual bool initialize() override;
		virtual void finalize() override;
	};
}

