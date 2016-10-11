#include "BaseGameLog.h"

gov::BaseGameLog::BaseGameLog()
{
}

gov::BaseGameLog::BaseGameLog(const std::string & logName)
{
	create(logName);
}

gov::BaseGameLog::~BaseGameLog()
{
	close();
}

bool gov::BaseGameLog::create(const std::string & logName)
{
	close();

	_logStream.open(logName, std::ios_base::out);
	if (_logStream.fail())
		return false;

	return true;
}

void gov::BaseGameLog::log(const std::string & message)
{
	if (!_logStream.bad())
		_logStream.write(message.c_str(), message.size());
}

void gov::BaseGameLog::close()
{
	if (!_logStream.bad())
		_logStream.close();
}
