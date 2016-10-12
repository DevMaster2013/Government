#include "BaseGameModule.h"


gov::BaseGameModule::BaseGameModule()
	: BaseGameObject("", "")
	, _subModules()
{
}

gov::BaseGameModule::BaseGameModule(const std::string& name, const std::string& id)
	: BaseGameObject(name, id)
	, _subModules()
{
}

gov::BaseGameModule::~BaseGameModule()
{
}

void gov::BaseGameModule::addSubModule(gov::BaseGameModule* subModule)
{
	if (_subModules.find(subModule->getID()) == _subModules.end())
		_subModules.insert(std::make_pair(subModule->getID(), subModule));
}

void gov::BaseGameModule::removeSubModule(const std::string& moduleID)
{
	if (_subModules.find(moduleID) != _subModules.end())
		_subModules.erase(moduleID);
}

gov::BaseGameModule* gov::BaseGameModule::getSubModule(const std::string& moduleID)
{
	if (_subModules.find(moduleID) != _subModules.end())
		_subModules[moduleID];
	return nullptr;
}

bool gov::BaseGameModule::initialize()
{
	if (!BaseGameObject::initialize())
		return false;
	for (auto& module : _subModules)
		if (!module.second->initialize())
			return false;
	return true;
}

void gov::BaseGameModule::finalize()
{
	for (auto& module : _subModules)
		module.second->finalize();

	_subModules.clear();
	BaseGameObject::finalize();
}

void gov::BaseGameModule::update(double elapsedTime)
{
	BaseGameObject::update(elapsedTime);

	for (auto& module : _subModules)
		module.second->update(elapsedTime);
}
