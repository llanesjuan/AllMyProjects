// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CATMOUSE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CATMOUSE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CATMOUSE_EXPORTS
#define CATMOUSE_API __declspec(dllexport)
#else
#define CATMOUSE_API __declspec(dllimport)
#endif

// This class is exported from the CatMouse.dll
class CATMOUSE_API CCatMouse {
public:
	CCatMouse(void);
	// TODO: add your methods here.
};

extern CATMOUSE_API int nCatMouse;

CATMOUSE_API int fnCatMouse(void);
