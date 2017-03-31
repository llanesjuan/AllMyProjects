// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DRAWINGBOOK_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DRAWINGBOOK_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DRAWINGBOOK_EXPORTS
#define DRAWINGBOOK_API __declspec(dllexport)
#else
#define DRAWINGBOOK_API __declspec(dllimport)
#endif

// This class is exported from the DrawingBook.dll
class DRAWINGBOOK_API CDrawingBook {
public:
	CDrawingBook(void);
	// TODO: add your methods here.
};

extern DRAWINGBOOK_API int nDrawingBook;

DRAWINGBOOK_API int fnDrawingBook(void);
