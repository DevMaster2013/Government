
#include "..\..\GameModule\GameModule.h"
#include <iostream>

int main()
{
	gov::GameTimeSpan timeSpan1 = gov::GameTimeSpan::fromMilliseconds(246546121500.0);
	gov::GameTimeSpan timeSpan2 = gov::GameTimeSpan::fromMilliseconds(246546121501.0);
	auto check = timeSpan1 == timeSpan2;

	return 0;
}