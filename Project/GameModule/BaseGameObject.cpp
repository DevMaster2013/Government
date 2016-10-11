#include "BaseGameObject.h"

gov::BaseGameObject::BaseGameObject()
	: _name("")
	, _id("")
{
}

gov::BaseGameObject::BaseGameObject(const std::string & name, const std::string & id)
	: _name(name)
	, _id(id)
{
}

gov::BaseGameObject::~BaseGameObject()
{
}

const std::string & gov::BaseGameObject::getName() const
{
	return _name;
}

void gov::BaseGameObject::setName(const std::string & objectName)
{
	_name.assign(objectName);
}

const std::string & gov::BaseGameObject::getID() const
{
	return _id;
}

void gov::BaseGameObject::setID(const std::string & objectID)
{
	_id.assign(objectID);
}

bool gov::BaseGameObject::initialize()
{
	return false;
}

void gov::BaseGameObject::finalize()
{
	_name = "";
	_id = "";
}

void gov::BaseGameObject::update()
{
}
