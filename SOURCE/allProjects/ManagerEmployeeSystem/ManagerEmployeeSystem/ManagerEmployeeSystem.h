// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MANAGEREMPLOYEESYSTEM_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MANAGEREMPLOYEESYSTEM_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MANAGEREMPLOYEESYSTEM_EXPORTS
#define MANAGEREMPLOYEESYSTEM_API __declspec(dllexport)
#else
#define MANAGEREMPLOYEESYSTEM_API __declspec(dllimport)
#endif

// This class is exported from the ManagerEmployeeSystem.dll
class MANAGEREMPLOYEESYSTEM_API CManagerEmployeeSystem {
public:
	CManagerEmployeeSystem(void);
	// TODO: add your methods here.
};

extern MANAGEREMPLOYEESYSTEM_API int nManagerEmployeeSystem;

MANAGEREMPLOYEESYSTEM_API int fnManagerEmployeeSystem(void);
