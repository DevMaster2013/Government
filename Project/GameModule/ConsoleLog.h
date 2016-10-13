#pragma once
#include "IGameLog.h"

namespace gov
{
	class ConsoleLog : public IGameLog
	{
	public:
		///
		/// The default constructor
		///
		ConsoleLog();

		///
		/// The destructor of the game log
		///
		virtual ~ConsoleLog();

	public:
		///
		/// Inheretied from IGameLog
		///
		virtual bool create(const std::string& logName) override;
		virtual void log(const std::string& message) override;
		virtual void close() override;
	};
}

