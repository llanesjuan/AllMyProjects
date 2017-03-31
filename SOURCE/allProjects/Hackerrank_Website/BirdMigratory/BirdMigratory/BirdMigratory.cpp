// BirdMigratory.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "BirdMigratory.h"


// This is an example of an exported variable
BIRDMIGRATORY_API int nBirdMigratory=0;

// This is an example of an exported function.
BIRDMIGRATORY_API int fnBirdMigratory(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see BirdMigratory.h for the class definition
CBirdMigratory::CBirdMigratory()
{
    return;
}
