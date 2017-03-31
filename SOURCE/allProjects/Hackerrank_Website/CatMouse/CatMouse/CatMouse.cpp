// CatMouse.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "CatMouse.h"


// This is an example of an exported variable
CATMOUSE_API int nCatMouse=0;

// This is an example of an exported function.
CATMOUSE_API int fnCatMouse(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see CatMouse.h for the class definition
CCatMouse::CCatMouse()
{
    return;
}
