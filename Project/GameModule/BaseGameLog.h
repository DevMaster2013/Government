#pragma once

#include "IGameLog.h"
#include <fstream>
#include <string>

namespace gov
{
	///
	/// The basic log for the game
	///
	class BaseGameLog : public IGameLog
	{
	protected:
		std::ofstream _logStream;	/// The stream used in logging messages

	public:
		///
		/// The default constructor
		///
		BaseGameLog();

		///
		/// The initialization constructor
		///
		BaseGameLog(const std::string& fileName);

		///
		/// The destructor of the game log
		///
		virtual ~BaseGameLog();

	public:
		///
		/// Inheretied from IGameLog
		///
		virtual bool create(const std::string& fileName) override;
		virtual void log(const std::string& message) override;
		virtual void close() override;
	};
}
