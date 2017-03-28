#include "Manager.h"



list<string> Manager::parseManager(string str)
{
	list<string>managerList;
	list<string>managerEmployeeList;
	char *charStr = new char[str.length() + 1];
	strcpy(charStr, str.c_str());
	char *managerEmployee = strtok(charStr, ".");
	while (managerEmployee != NULL) {
		managerEmployeeList.push_back(string(managerEmployee));
		managerEmployee = strtok(NULL, ".");
	}
	list<string>::iterator itrList;
	for (itrList = managerEmployeeList.begin(); itrList != managerEmployeeList.end(); itrList++) {
		string manager = (*itrList).substr(0, (*itrList).find("-", 0));
		managerList.push_back(manager);
	}
	return managerList;
}

Manager::Manager()
{
}


Manager::~Manager()
{
}
