#include "BaseGameLog.h"

gov::BaseGameLog::BaseGameLog()
{
}

gov::BaseGameLog::BaseGameLog(const std::string & fileName)
{
	create(fileName);
}

gov::BaseGameLog::~BaseGameLog()
{
	close();
}

bool gov::BaseGameLog::create(const std::string & fileName)
{
	close();

	_logStream.open(fileName, std::ios_base::out);
	if (_logStream.fail())
		return false;

	return true;
}

void gov::BaseGameLog::log(const std::string & message)
{
	std::string msgT = message + std::string("\n");
	if (!_logStream.bad())
		_logStream.write(msgT.c_str(), msgT.size());
}

void gov::BaseGameLog::close()
{
	if (!_logStream.bad())
		_logStream.close();
}
