#include "ConsoleLog.h"
#include <iostream>

gov::ConsoleLog::ConsoleLog()
{
}

gov::ConsoleLog::~ConsoleLog()
{
}

bool gov::ConsoleLog::create(const std::string & logName)
{
	return true;
}

void gov::ConsoleLog::log(const std::string & message)
{
	std::cout << message << std::endl;
}

void gov::ConsoleLog::close()
{
}
