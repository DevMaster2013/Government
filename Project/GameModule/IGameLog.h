#pragma once

#include <string>

namespace gov
{
	class IGameLog
	{
	public:
		///
		/// Create the log stream
		///
		virtual bool create(const std::string& logName) = 0;

		///
		/// Log the message into the logging stream
		///
		virtual void log(const std::string& message) = 0;

		///
		/// Close the log stream
		///
		virtual void close() = 0;
	};
}
