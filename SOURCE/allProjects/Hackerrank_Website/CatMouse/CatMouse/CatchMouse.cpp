#include "CatchMouse.h"



string CatchMouse::mouseCatcher(int cat1, int cat2, int mouse)
{	
	if (abs(mouse - cat1) > abs(mouse - cat2)) {
		return "B";
	}
	else if (abs(mouse - cat1) < abs(mouse - cat2)) {
		return "A";
	}
	return "M";
}

CatchMouse::CatchMouse()
{
}


CatchMouse::~CatchMouse()
{
}
