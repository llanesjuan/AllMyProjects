#include "Employee.h"



list<list<string>> Employee::parseEmployee(string str)
{
	char *employee;
	list<string>employeeList;
	list<string>employeeListGroup;
	list < list<string>>employeeListList;
	list<string>managerEmployeeList;
	char *charStr = new char[str.length() + 1];
	strcpy(charStr, str.c_str());
	char *managerEmployee = strtok(charStr, ".");
	while (managerEmployee != NULL) {
		//pushing all managers and employees as string between dots in the vector string
		managerEmployeeList.push_back(string(managerEmployee));
		managerEmployee = strtok(NULL, ".");
	}
	list<string>::iterator itrList;
	for (itrList = managerEmployeeList.begin(); itrList != managerEmployeeList.end(); itrList++) {
		//separating managers from employees, keep the latest
		int indexStartEmployee = (*itrList).find("-", 0);
		string allEmployees = (*itrList).substr(indexStartEmployee + 2, 200);
		char *charAllEmployees = new char[ allEmployees.length() + 1 ];
		strcpy(charAllEmployees, allEmployees.c_str());
		employee = strtok(charAllEmployees, ",");
		while (employee != NULL) {
			//create a list of employees with same manager
			employeeList.push_back(employee);
			employee = strtok(NULL, ",");
		}
		//adding a list of employees to big list of list
		employeeListList.push_back(employeeList);
		employeeList.clear();
	}
	return employeeListList;
}

Employee::Employee()
{
}


Employee::~Employee()
{
}
