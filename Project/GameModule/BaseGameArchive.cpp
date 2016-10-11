#include "BaseGameArchive.h"

gov::BaseGameArchive::BaseGameArchive()
	: _archiveStream()
	, _forReading(false)
{
}

gov::BaseGameArchive::BaseGameArchive(const std::string & fileName, bool isRead)
{
	open(fileName, isRead);
}

gov::BaseGameArchive::~BaseGameArchive()
{
	close();
}

bool gov::BaseGameArchive::open(const std::string & fileName, bool isRead)
{
	_forReading = isRead;
	_archiveStream.open(fileName, _forReading ? std::ios_base::in : std::ios_base::out);
	if (_archiveStream.bad())
		return false;
	return true;
}

void gov::BaseGameArchive::close()
{
	if (!_archiveStream.bad())
		_archiveStream.close();
}
