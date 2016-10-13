#include <sstream>
#include "LogManager.h"
#include "DateTime.h"

gov::LogManager* gov::LogManager::_singleInstance = nullptr;

gov::LogManager::LogManager()
{
}

gov::LogManager::~LogManager()
{
}

gov::LogManager * gov::LogManager::getInstance()
{
	if (_singleInstance == nullptr)
		_singleInstance = new gov::LogManager();
	return _singleInstance;
}

void gov::LogManager::finalizeLogManager()
{
	if (_singleInstance != nullptr)
	{
		_singleInstance->finalize();
		delete _singleInstance;
	}
}

void gov::LogManager::addLog(const std::string & logName, IGameLog * gameLog)
{
	if (_loggers.find(logName) == _loggers.end())
		_loggers.insert(std::make_pair(logName, gameLog));
}

gov::IGameLog * gov::LogManager::getLog(const std::string & logName)
{
	if (_loggers.find(logName) != _loggers.end())
		return _loggers[logName];
	return nullptr;
}

void gov::LogManager::removeLog(const std::string & logName)
{
	if (_loggers.find(logName) != _loggers.end())
		_loggers.erase(logName);
}

void gov::LogManager::log(const std::string & message)
{	
	auto nowTime = DateTime::now();

	std::stringstream sst;
	sst << nowTime.getDay() << "/" << nowTime.getMonth() << "/" << nowTime.getYear() << " ";
	sst << nowTime.getHour() << ":" << nowTime.getMinute() << ":" << nowTime.getSecond() << " - " << message;

	for (auto log : _loggers)
		log.second->log(sst.str());
}

bool gov::LogManager::initialize()
{
	return BaseGameObject::initialize();
}

void gov::LogManager::finalize()
{
	for (auto& log : _loggers)
	{
		log.second->close();
		delete log.second;
	}
	_loggers.clear();

	return BaseGameObject::finalize();
}
