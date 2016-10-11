#pragma once

#include <fstream>
#include <string>

namespace gov
{
	///
	/// The basic log for the game
	///
	class BaseGameLog
	{
	private:
		std::ofstream _logStream;	/// The stream used in logging messages

	public:
		///
		/// The default constructor
		///
		BaseGameLog();

		///
		/// The initialization constructor
		///
		BaseGameLog(const std::string& logName);

		///
		/// The destructor of the game log
		///
		virtual ~BaseGameLog();

	public:
		///
		/// Create the log stream
		///
		virtual bool create(const std::string& logName);

		///
		/// Log the message into the logging stream
		///
		virtual void log(const std::string& message);

		///
		/// Close the log stream
		///
		virtual void close();
	};
}
