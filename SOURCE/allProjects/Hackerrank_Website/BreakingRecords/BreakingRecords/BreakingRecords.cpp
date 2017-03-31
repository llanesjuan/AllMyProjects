// BreakingRecords.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "BreakingRecords.h"


// This is an example of an exported variable
BREAKINGRECORDS_API int nBreakingRecords=0;

// This is an example of an exported function.
BREAKINGRECORDS_API int fnBreakingRecords(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see BreakingRecords.h for the class definition
CBreakingRecords::CBreakingRecords()
{
    return;
}
