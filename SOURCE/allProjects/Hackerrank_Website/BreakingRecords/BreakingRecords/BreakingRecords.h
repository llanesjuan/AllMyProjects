// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the BREAKINGRECORDS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// BREAKINGRECORDS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef BREAKINGRECORDS_EXPORTS
#define BREAKINGRECORDS_API __declspec(dllexport)
#else
#define BREAKINGRECORDS_API __declspec(dllimport)
#endif

// This class is exported from the BreakingRecords.dll
class BREAKINGRECORDS_API CBreakingRecords {
public:
	CBreakingRecords(void);
	// TODO: add your methods here.
};

extern BREAKINGRECORDS_API int nBreakingRecords;

BREAKINGRECORDS_API int fnBreakingRecords(void);
