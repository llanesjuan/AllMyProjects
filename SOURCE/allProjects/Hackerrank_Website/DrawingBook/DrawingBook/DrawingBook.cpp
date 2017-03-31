// DrawingBook.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DrawingBook.h"


// This is an example of an exported variable
DRAWINGBOOK_API int nDrawingBook=0;

// This is an example of an exported function.
DRAWINGBOOK_API int fnDrawingBook(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see DrawingBook.h for the class definition
CDrawingBook::CDrawingBook()
{
    return;
}
