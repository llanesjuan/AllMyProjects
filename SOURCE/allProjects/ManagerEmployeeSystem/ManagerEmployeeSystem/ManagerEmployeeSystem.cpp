// ManagerEmployeeSystem.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ManagerEmployeeSystem.h"


// This is an example of an exported variable
MANAGEREMPLOYEESYSTEM_API int nManagerEmployeeSystem=0;

// This is an example of an exported function.
MANAGEREMPLOYEESYSTEM_API int fnManagerEmployeeSystem(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see ManagerEmployeeSystem.h for the class definition
CManagerEmployeeSystem::CManagerEmployeeSystem()
{
    return;
}
