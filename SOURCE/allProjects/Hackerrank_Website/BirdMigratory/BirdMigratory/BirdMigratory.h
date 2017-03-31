// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the BIRDMIGRATORY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// BIRDMIGRATORY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef BIRDMIGRATORY_EXPORTS
#define BIRDMIGRATORY_API __declspec(dllexport)
#else
#define BIRDMIGRATORY_API __declspec(dllimport)
#endif

// This class is exported from the BirdMigratory.dll
class BIRDMIGRATORY_API CBirdMigratory {
public:
	CBirdMigratory(void);
	// TODO: add your methods here.
};

extern BIRDMIGRATORY_API int nBirdMigratory;

BIRDMIGRATORY_API int fnBirdMigratory(void);
